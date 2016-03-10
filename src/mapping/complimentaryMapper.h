#ifndef thirdperson_complimentarymapper
#define thirdperson_complimentarymapper

#include "Common.h"
#include "BaseInput.h"
#include "BaseOutput.h"

// Maps one input to two complimentary outputs
class ComplimentaryMapper {
    
public:
    void setup(BaseInput *input, BaseOutput *op1, BaseOutput *op2);
    void update();
    
private:
    
    // The single input
    BaseInput  *ip_;
    
    // The pair of outputs
    OutputPair op_;
    
    // Target values calculated on update
    ValuePair  tgt_;
    
    // The previous value pair used, kept for easing
    ValuePair  prv_;
    
};


#endif
