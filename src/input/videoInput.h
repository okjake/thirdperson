#ifndef thirdperson_videoinput
#define thirdperson_videoinput

#include "BaseInput.h"

class VideoInput : public BaseInput
{
    public:
        VideoInput(){};
        ~VideoInput(){};
        void openInputDevice(short cap_width, short cap_height, short cap_rate);
    
    private:
        ofVideoPlayer video_;

};
#endif