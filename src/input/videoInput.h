
#ifndef __sweetSpot__videoInput__
#define __sweetSpot__videoInput__

#include "baseInput.h"

class videoInput : public baseInput
{
    public:
        videoInput(){};
        ~videoInput(){};
        void openInputDevice(short captureWidth, short captureHeight, short captureRate);
    
    private:
        ofVideoPlayer mVideoPlayer;

};
#endif /* defined(__sweetSpot__videoInput__) */
