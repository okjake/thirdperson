#include "VideoInput.h"

void VideoInput::openInputDevice(short captureWidth, short captureHeight, short captureRate) {
    mVid = &mVideoPlayer;
    mVideoPlayer.loadMovie("test/test.mov");
    mVideoPlayer.play();
}