#ifndef FIREFOX_H
#define FIREFOX_H

#include <QObject>
#include <QDir>
#include <QDebug>
#include <QFileInfo>
#include <sys/types.h>
#include <unistd.h>
#include "exec.h"

class FirefoxHandle : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE bool isEnabled() const {
        setuid(0);
        system("whoami");
        QFileInfo checkFile("/usr/share/firefox-default-handler/enabled");
        return checkFile.exists();
    }

    Q_INVOKABLE bool isEnabledBeta() const {
        setuid(0);
        QFileInfo checkFile("/usr/share/firefox-default-handler/enabled_beta");
        return checkFile.exists();
    }

    Q_INVOKABLE bool enableBeta() const {
        setuid(0);
        system("whoami");
        exec("mkdir -p /usr/share/firefox-default-handler/backup");
        exec("cp /opt/alien/system/build.prop /usr/share/firefox-default-handler/backup/build.prop");
        exec("echo persist.service.adb.enable=1 >> /opt/alien/system/build.prop");
        exec("echo service.adb.tcp.port=5555 >> /opt/alien/system/build.prop");
        exec("touch /usr/share/firefox-default-handler/enabled_beta");
        exec("mv /usr/share/applications/open-url.desktop /usr/share/firefox-default-handler/backup/open-url.desktop");
        exec("cp /usr/share/firefox-default-handler/open-url-beta.desktop /usr/share/applications/open-url.desktop");
        exec("cp /usr/share/firefox-default-handler/restart-adb.sh /etc/profile.d/restart-adb.sh");
        exec("chmod +x /etc/profile.d/restart-adb.sh");
        exec("update-desktop-database");
        exec("systemctl restart aliendalvik.service");
        exec("/opt/alien/system/bin/adb kill-server");
        exec("/opt/alien/system/bin/adb devices");
        return true;
    }

    Q_INVOKABLE bool enable() const {
        setuid(0);
        system("whoami");
        exec("mkdir -p /usr/share/firefox-default-handler/backup");
        exec("cp /opt/alien/system/build.prop /usr/share/firefox-default-handler/backup/build.prop");
        exec("echo persist.service.adb.enable=1 >> /opt/alien/system/build.prop");
        exec("echo service.adb.tcp.port=5555 >> /opt/alien/system/build.prop");
        exec("touch /usr/share/firefox-default-handler/enabled");
        exec("mv /usr/share/applications/open-url.desktop /usr/share/firefox-default-handler/backup/open-url.desktop");
        exec("cp /usr/share/firefox-default-handler/open-url.desktop /usr/share/applications/open-url.desktop");
        exec("cp /usr/share/firefox-default-handler/restart-adb.sh /etc/profile.d/restart-adb.sh");
        exec("chmod +x /etc/profile.d/restart-adb.sh");
        exec("update-desktop-database");
        exec("systemctl restart aliendalvik.service");
        exec("/opt/alien/system/bin/adb kill-server");
        exec("/opt/alien/system/bin/adb devices");
        return true;
    }

    Q_INVOKABLE bool disable() const {
        setuid(0);
        system("whoami");
        exec("cp /usr/share/firefox-default-handler/backup/build.prop /opt/alien/system/build.prop");
        exec("rm -rf /usr/share/firefox-default-handler/enabled");
        exec("cp /usr/share/firefox-default-handler/backup/open-url.desktop /usr/share/applications/open-url.desktop");
        exec("rm -rf /etc/profile.d/restart-adb.sh");
        exec("update-desktop-database");
        exec("systemctl restart aliendalvik.service");
        exec("/opt/alien/system/bin/adb kill-server");
        return true;
    }

    Q_INVOKABLE bool disableBeta() const {
        setuid(0);
        system("whoami");
        exec("cp /usr/share/firefox-default-handler/backup/build.prop /opt/alien/system/build.prop");
        exec("rm -rf /usr/share/firefox-default-handler/enabled_beta");
        exec("cp /usr/share/firefox-default-handler/backup/open-url.desktop /usr/share/applications/open-url.desktop");
        exec("rm -rf /etc/profile.d/restart-adb.sh");
        exec("update-desktop-database");
        exec("systemctl restart aliendalvik.service");
        exec("/opt/alien/system/bin/adb kill-server");
        return true;
    }
};

#endif // FIREFOX_H
