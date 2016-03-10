#ifndef thirdperson_baseoutput
#define thirdperson_baseoutput

class BaseOutput {

    public:
        BaseOutput() { mOutputIndex = sOutputCount++; }
        ~BaseOutput(){ sOutputCount--; }
    
        BaseOutput(const BaseOutput&) { sOutputCount++; }
    
        virtual void setup() = 0;
        virtual void update() = 0;
        virtual void act() = 0;
        virtual void setLevel(short level) = 0;
    
    protected:
        static unsigned int sOutputCount;
        unsigned int        mOutputIndex;

    
};

#endif
