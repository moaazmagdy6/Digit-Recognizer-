TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    initiator.cpp

DISTFILES += \
    ../Desktop/Desktop Garbage/Pics/15-12-large-modern-pink-abstract-art-home-decor.jpg \
    test.jpg \
    draft

INCLUDEPATH += /usr/include/opencv
#LIBS += -L/usr/local/lib \
#-lopencv_core \
#-lopencv_imgproc \
#-lopencv_highgui \
#-lopencv_ml \
#-lopencv_video \
#-lopencv_features2d \
#-lopencv_calib3d \
#-lopencv_objdetect \
#-lopencv_contrib \
#-lopencv_legacy \
#-lopencv_flann
LIBS += `pkg-config opencv --libs`
