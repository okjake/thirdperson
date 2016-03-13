#ifndef thirdperson_camerainput
#define thirdperson_camerainput

#include "BaseInput.h"

class CameraInput : public BaseInput
{
public:
    CameraInput(){};
    ~CameraInput(){};
    void openInputDevice(short cap_width, short cap_height, short cap_rate);

private:
    ofVideoGrabber grab_;
};

#endif
