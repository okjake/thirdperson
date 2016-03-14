#ifndef thirdperson_audiooutput
#define thirdperson_audiooutput

#include "base_output.h"
#include "ofMain.h"

// Plays audio that will be modulated by inputs
class AudioOutput : public BaseOutput {
    
    public:
        AudioOutput(){};
        ~AudioOutput(){};

        void setup();
        void setup(const char* filepath);
        void update();
        void act();
        void setLevel(short level);

    private:
        // The main functionality happens here
        ofSoundPlayer audio_;
    
};

#endif
