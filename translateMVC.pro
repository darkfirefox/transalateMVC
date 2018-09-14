# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = translateMVC

CONFIG += sailfishapp

SOURCES += src/translateMVC.cpp \
    src/historymodel.cpp \
    src/servicehistory.cpp \
    src/database.cpp \
    src/listelementhistory.cpp \
    src/databaseparser.cpp \
    src/listrecords.cpp \
    src/elementhistory.cpp \
    src/servicehttp.cpp \
    src/networkmanager.cpp \
    src/requestconverter.cpp \
    src/translatemodel.cpp \
    src/streamdata.cpp \
    src/services.cpp

DISTFILES += qml/translateMVC.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    rpm/translateMVC.changes.in \
    rpm/translateMVC.changes.run.in \
    rpm/translateMVC.spec \
    rpm/translateMVC.yaml \
    translations/*.ts \
    translateMVC.desktop \
    qml/pages/HistoryPage.qml

SAILFISHAPP_ICONS = 86x86 108x108 128x128 172x172

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/translateMVC-de.ts

HEADERS += \
    src/historymodel.h \
    src/servicehistory.h \
    src/database.h \
    src/listelementhistory.h \
    src/databaseparser.h \
    src/listrecords.h \
    src/elementhistory.h \
    src/servicehttp.h \
    src/networkmanager.h \
    src/requestconverter.h \
    src/translatemodel.h \
    src/streamdata.h \
    src/iservicehtttp.h \
    src/iservicehistory.h \
    src/services.h
QT+=sql
