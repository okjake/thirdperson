#ifndef thirdperson_linearmapper
#define thirdperson_linearmapper

#include "Common.h"
#include "BaseInput.h"
#include "BaseOutput.h"

// Simple linear mapper
class LinearMapper {
    
public:
    void setup(BaseInput *input, BaseOutput *output, SWEETSPOT_SECTOR sector);
    void update();
    
private:
    
    // The input
    BaseInput  *input_;
    
    // The output
    BaseOutput *output_;
    
    // Target value
    short target_;
    
    // Previous value for easing
    short previous_;
    
    // Which sector is to be mapped
    SWEETSPOT_SECTOR sector_;
};


#endif
