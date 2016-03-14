#ifndef thirdperson_baseoutput
#define thirdperson_baseoutput

// Interface for outputs to use
class BaseOutput {

public:
    BaseOutput() { index_instance_ = count_instance_++; }
    ~BaseOutput(){ count_instance_--; }

    BaseOutput(const BaseOutput&) { count_instance_++; }

    virtual void setup() = 0;
    virtual void update() = 0;
    virtual void act() = 0;
    virtual void setLevel(short level) = 0;
    
protected:
    static unsigned int count_instance_;
    unsigned int index_instance_;

};

#endif
