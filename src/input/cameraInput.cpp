
#include "CameraInput.h"

void CameraInput::openInputDevice(short cap_width, short cap_height, short cap_rate) {
    vid_ = &grab_;
    grab_.setUseTexture(false);
    grab_.setDeviceID(input_idx_);
    grab_.setPixelFormat(OF_PIXELS_RGB);
    grab_.setDesiredFrameRate(cap_rate);
    grab_.initGrabber(cap_width, cap_height);
}
