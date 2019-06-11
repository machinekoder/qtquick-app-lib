#ifndef VIBRATOR_H
#define VIBRATOR_H

#include <QObject>

#if defined(Q_OS_ANDROID)
#include <QAndroidJniEnvironment>
#include <QAndroidJniObject>
#endif

class Vibrator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int interval READ interval WRITE setInterval NOTIFY intervalChanged)
    Q_PROPERTY(bool available READ available NOTIFY availableChanged)

public:
    explicit Vibrator(QObject *parent = 0);
    int interval() const;
    bool available() const;

public slots:
    void vibrate();

    void setInterval(int interval);

signals:
    void intervalChanged(int interval);
    void availableChanged(bool available);

private:
#if defined(Q_OS_ANDROID)
    QAndroidJniObject vibratorService;
#endif
    int m_interval;
    bool m_available;
};

#endif // VIBRATOR_H
