QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    funcs/http_post/http_client.cpp \
    funcs/http_post/http_post_widget.cpp \
    funcs/http_post/http_server.cpp \
    funcs/kbq/kbqwidget.cpp \
    funcs/hex_txt_convert/hex_txt_convert.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    funcs/http_post/http_client.h \
    funcs/http_post/http_post_widget.h \
    funcs/http_post/http_server.h \
    funcs/kbq/kbqwidget.h \
    funcs/hex_txt_convert/hex_txt_convert.h \
    widget.h

FORMS += \
    funcs/http_post/http_client.ui \
    funcs/http_post/http_post_widget.ui \
    funcs/http_post/http_server.ui \
    funcs/kbq/kbqwidget.ui \
    funcs/hex_txt_convert/hex_txt_convert.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += resource/cyg_tool.qrc

RC_FILE = resource/cyg_tool.rc
