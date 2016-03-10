

#ifndef __sweetspot__audioOutput__
#define __sweetspot__audioOutput__

#include "baseOutput.h"
#include "ofMain.h"

class audioOutput : public baseOutput {
    
    public:
        audioOutput(){};
        ~audioOutput(){};
    
        void setup();
        void setup(const char* filepath);
        void update();
        void act();
        void setLevel(short level);
    
    private:
        ofSoundPlayer mTrack;
    
};

#endif /* defined(__sweetspot__audioOutput__) */
