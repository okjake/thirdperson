
#include "cameraInput.h"

void cameraInput::openInputDevice(short captureWidth, short captureHeight, short captureRate) {
    mVid = &mVideoGrabber;
    mVideoGrabber.setUseTexture(false);
    mVideoGrabber.setDeviceID(mInputIndex+1);
    mVideoGrabber.setPixelFormat(OF_PIXELS_RGB);
    mVideoGrabber.setDesiredFrameRate(captureRate);
    mVideoGrabber.initGrabber(captureWidth, captureHeight);
}
