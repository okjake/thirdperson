
/*
 * Base class for output
 */

#ifndef __sweetspot__baseOutput__
#define __sweetspot__baseOutput__

class baseOutput {

    public:
        baseOutput() { mOutputIndex = sOutputCount++; }
        ~baseOutput(){ sOutputCount--; }
    
        baseOutput(const baseOutput&) { sOutputCount++; }
    
        virtual void setup() = 0;
        virtual void update() = 0;
        virtual void act() = 0;
        virtual void setLevel(short level) = 0;
    
    protected:
        static unsigned int sOutputCount;
        unsigned int        mOutputIndex;

    
};

#endif /* defined(__sweetspot__baseOutput__) */
