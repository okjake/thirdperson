#ifndef thirdperson_videoinput
#define thirdperson_videoinput

#include "BaseInput.h"

class VideoInput : public BaseInput
{
    public:
        VideoInput(){};
        ~VideoInput(){};
        void openInputDevice(short captureWidth, short captureHeight, short captureRate);
    
    private:
        ofVideoPlayer mVideoPlayer;

};
#endif