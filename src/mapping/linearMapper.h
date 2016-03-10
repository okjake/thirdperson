#ifndef thirdperson_linearmapper
#define thirdperson_linearmapper

#include "Common.h"
#include "BaseInput.h"
#include "BaseOutput.h"

class LinearMapper {
    
public:
    void setup(BaseInput *ip, BaseOutput *op, SWEETSPOT_SECTOR sector);
    void update();
    
private:
    BaseInput  *ip_;
    BaseOutput *op_;
    
    short tgt_;
    short prv_;
    
    SWEETSPOT_SECTOR sector_;
};


#endif
