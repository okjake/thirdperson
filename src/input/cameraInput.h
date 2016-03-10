
#ifndef __sweetspot__cameraInput__
#define __sweetspot__cameraInput__

#include "baseInput.h"

class cameraInput : public baseInput
{
public:
    cameraInput(){};
    ~cameraInput(){};
    void openInputDevice(short captureWidth, short captureHeight, short captureRate);    

private:
    ofVideoGrabber mVideoGrabber;
};

#endif /* defined(__sweetspot__cameraInput__) */
