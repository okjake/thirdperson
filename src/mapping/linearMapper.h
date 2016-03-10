#ifndef thirdperson_linearmapper
#define thirdperson_linearmapper

#include "Common.h"
#include "BaseInput.h"
#include "BaseOutput.h"

// Simple linear mapper
class LinearMapper {
    
public:
    void setup(BaseInput *ip, BaseOutput *op, SWEETSPOT_SECTOR sector);
    void update();
    
private:
    
    // The input
    BaseInput  *ip_;
    
    // The output
    BaseOutput *op_;
    
    // Target value
    short tgt_;
    
    // Previous value for easing
    short prv_;
    
    // Which sector is to be mapped
    SWEETSPOT_SECTOR sector_;
};


#endif
