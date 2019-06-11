#include "vibrator.h"
#include <QDebug>

Vibrator::Vibrator(QObject *parent)
    : QObject(parent)
    , m_interval(500)
    , m_available(false)
{
#if defined(Q_OS_ANDROID)
    QAndroidJniObject vibroString = QAndroidJniObject::fromString("vibrator");
    QAndroidJniObject activity = QAndroidJniObject::callStaticObjectMethod("org/qtproject/qt5/android/QtNative", "activity", "()Landroid/app/Activity;");
    QAndroidJniObject appctx = activity.callObjectMethod("getApplicationContext","()Landroid/content/Context;");
    vibratorService = appctx.callObjectMethod("getSystemService", "(Ljava/lang/String;)Ljava/lang/Object;", vibroString.object<jstring>());
    jboolean hasvibro = vibratorService.callMethod<jboolean>("hasVibrator", "()Z");
    if (hasvibro) {
        m_available = true;
        emit availableChanged(true);
    }
#endif
}

int Vibrator::interval() const
{
    return m_interval;
}

bool Vibrator::available() const
{
    return m_available;
}

#if defined(Q_OS_ANDROID)
void Vibrator::vibrate() {
    if (vibratorService.isValid()) {
        vibratorService.callMethod<void>("vibrate", "(J)V", static_cast<jlong>(m_interval));
    } else {
        qDebug() << "No vibrator service available";
    }
}
#else
void Vibrator::vibrate() {
}

#endif

void Vibrator::setInterval(int interval)
{
    if (m_interval == interval)
        return;

    m_interval = interval;
    emit intervalChanged(interval);
}
