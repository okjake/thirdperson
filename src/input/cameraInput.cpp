
#include "CameraInput.h"

void CameraInput::openInputDevice(short captureWidth, short captureHeight, short captureRate) {
    mVid = &mVideoGrabber;
    mVideoGrabber.setUseTexture(false);
    mVideoGrabber.setDeviceID(mInputIndex);
    mVideoGrabber.setPixelFormat(OF_PIXELS_RGB);
    mVideoGrabber.setDesiredFrameRate(captureRate);
    mVideoGrabber.initGrabber(captureWidth, captureHeight);
}
