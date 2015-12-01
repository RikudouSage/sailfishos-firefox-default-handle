TARGET = firefox-default-handler

MY_FILES = \
other/restart-adb.sh \
other/open-url.desktop

OTHER_SOURCES += $$MY_FILES

my_resources.path = $$PREFIX/share/$$TARGET
my_resources.files = $$MY_FILES

INSTALLS += my_resources

CONFIG += sailfishapp

SOURCES += src/firefox-default-handler.cpp

OTHER_FILES += qml/firefox-default-handler.qml \
    qml/cover/CoverPage.qml \
    rpm/firefox-default-handler.changes.in \
    rpm/firefox-default-handler.spec \
    rpm/firefox-default-handler.yaml \
    translations/*.ts \
    firefox-default-handler.desktop \
    qml/pages/Main.qml

CONFIG += sailfishapp_i18n

TRANSLATIONS += translations/firefox-default-handler-cs_CZ.ts

HEADERS += \
    exec.h \
    Firefox.h

