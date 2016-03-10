#ifndef thirdperson_camerainput
#define thirdperson_camerainput

#include "BaseInput.h"

class CameraInput : public BaseInput
{
public:
    CameraInput(){};
    ~CameraInput(){};
    void openInputDevice(short captureWidth, short captureHeight, short captureRate);    

private:
    ofVideoGrabber mVideoGrabber;
};

#endif
