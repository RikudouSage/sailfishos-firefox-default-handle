#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include <QObject>
#include <QString>
#include <QQuickView>
#include <QQmlContext>
#include <QGuiApplication>
#include <QFileSystemWatcher>
#include <sys/types.h>
#include <unistd.h>
#include "Firefox.h"
#include <QDebug>




int main(int argc, char *argv[])
{
    qDebug() << setuid(0);
    FirefoxHandle fh;
    QGuiApplication *app = SailfishApp::application(argc, argv);
    QQuickView *view = SailfishApp::createView();
    QString qml = QString("qml/firefox-default-handler.qml");
    view->rootContext()->setContextProperty("fh",&fh);
    view->setSource(SailfishApp::pathTo(qml));
    view->show();
    return app->exec();
}


std::string exec(const char* cmd) {
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
        if(fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    return result;
}
