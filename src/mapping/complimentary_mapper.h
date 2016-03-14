#ifndef thirdperson_complimentarymapper
#define thirdperson_complimentarymapper

#include "common.h"
#include "base_input.h"
#include "base_output.h"

// Maps one input to two complimentary outputs
class ComplimentaryMapper {
    
public:
    void setup(BaseInput *input, BaseOutput *output1, BaseOutput *output2);
    void update();
    
private:
    
    // The single input
    BaseInput  *input_;
    
    // The pair of outputs
    OutputPair output_;
    
    // Target values calculated on update
    ValuePair  target_;
    
    // The previous value pair used, kept for easing
    ValuePair  previous_;
    
};


#endif
