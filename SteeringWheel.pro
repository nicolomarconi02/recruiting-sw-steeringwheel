QT += quick

SOURCES += \
        backend.cpp \
        main.cpp

resources.files =   main.qml \
                    Background.qml \
                    MiddleText.qml \
                    BottomText.qml \
                    TopText.qml \
                    TempBox.qml \
                    Box.qml

resources.prefix = /$${TARGET}
RESOURCES += resources

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    backend.h \
    data.hpp

CONFIG += qmltypes
QML_IMPORT_NAME = io.qt.SteeringWheel.backend
QML_IMPORT_MAJOR_VERSION = 1

DISTFILES += \
    Box.qml


