#ifndef thirdperson_audiooutput
#define thirdperson_audiooutput

#include "BaseOutput.h"
#include "ofMain.h"

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
    ofSoundPlayer audio_;
    
};

#endif
