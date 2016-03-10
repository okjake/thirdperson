
#include "videoInput.h"

void videoInput::openInputDevice(short captureWidth, short captureHeight, short captureRate) {
    mVid = &mVideoPlayer;
    mVideoPlayer.loadMovie("test/test.mov");
    mVideoPlayer.play();
}