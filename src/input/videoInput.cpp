#include "VideoInput.h"

void VideoInput::openInputDevice(short cap_width, short cap_height, short cap_rate) {
    feed_ = &video_;
    video_.loadMovie("test/test.mov");
    video_.play();
}