#ifndef thirdperson_oscoutput
#define thirdperson_oscoutput

#include "base_output.h"
#include "ofxOsc.h"

class OscOutput : public BaseOutput {

    public:
        OscOutput(){};
        ~OscOutput(){};
    
        void setup();
        void update();
        void act();
        void setLevel(short level);
    
    private:
        short level_;
        ofxOscSender sender_;
};

#endif
