
/*
 * Complimentary mapper
 * Maps one input to two complimentary outputs
 */

#ifndef thirdperson_complimentarymapper
#define thirdperson_complimentarymapper

#include "Common.h"
#include "BaseInput.h"
#include "BaseOutput.h"

class ComplimentaryMapper {
    
public:
    void setup(BaseInput *input, BaseOutput *op1, BaseOutput *op2);
    void update();
    
private:
    BaseInput  *ip_;
    OutputPair op_;
    ValuePair  tgt_;
    ValuePair  prv_;
    
};


#endif
