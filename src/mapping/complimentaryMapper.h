
/*
 * Complimentary mapper
 * Maps one input to two complimentary outputs
 */

#ifndef __sweetspot__complimentaryMapper__
#define __sweetspot__complimentaryMapper__

#include "common.h"
#include "baseInput.h"
#include "baseOutput.h"

class complimentaryMapper {
    
    public:
        void setup(baseInput *input, baseOutput *outputOne, baseOutput *outputTwo);
        void update();
    
    private:
        baseInput  *mInput;
        baseOutput *mOutputOne, *mOutputTwo;
  
        short mTgtOutputOne, mTgtOutputTwo, mPrevOutputOne, mPrevOutputTwo;
    
};


#endif /* defined(__sweetspot__complimentaryMapper__) */
