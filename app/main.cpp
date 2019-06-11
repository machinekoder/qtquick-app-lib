#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlFileSelector>
#include <QFile>

int main(int argc, char *argv[])
{
    QString initFile;
    
    QFile file("./main.qml");
    if (!file.exists())
    {
        initFile = QStringLiteral("qrc:///main.qml");
    }
    else {
        initFile = QStringLiteral("./main.qml");
    }

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImportPath(QStringLiteral("qml"));
    engine.addImportPath(QStringLiteral("plugins"));
    engine.addImportPath(QStringLiteral("assets:/qml"));

    engine.load(QUrl(initFile));
    return app.exec();
}
