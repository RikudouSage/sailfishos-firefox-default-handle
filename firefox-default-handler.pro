TARGET = firefox-default-handler

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

