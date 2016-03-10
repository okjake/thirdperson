
/*
 * TODO untested 
 * Linear mapper
 * Maps one sector of one input to a single output
 */

#ifndef __sweetspot__linearMapper__
#define __sweetspot__linearMapper__

#include "common.h"
#include "baseInput.h"
#include "baseOutput.h"

class linearMapper {
    
public:
    void setup(baseInput *input, baseOutput *output, SWEETSPOT_SECTOR sector);
    void update();
    
private:
    baseInput  *mInput;
    baseOutput *mOutput;
    short mTgtOutput, mPrevOutput;
    SWEETSPOT_SECTOR mSector;
};


#endif /* defined(__sweetspot__linearMapper__) */
