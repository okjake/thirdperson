

#include "complimentaryMapper.h"

void complimentaryMapper::setup(baseInput *input, baseOutput *outputOne, baseOutput *outputTwo) {
    mInput = input;
    mOutputOne = outputOne;
    mOutputTwo = outputTwo;
    mTgtOutputOne = mTgtOutputTwo = mPrevOutputOne = mPrevOutputTwo = 0;
}


void complimentaryMapper::update() {
    
    if (mInput->isSweetSpotOccupied()) {
        mTgtOutputOne = mTgtOutputTwo = 100;
    } else {
        mTgtOutputOne = mInput->getMeanProximity(SECTOR_LEFT);
        mTgtOutputTwo = mInput->getMeanProximity(SECTOR_RIGHT);
    }
    
    if (mTgtOutputOne > mPrevOutputOne) { mOutputOne->setLevel(++mPrevOutputOne); }
    else if (mTgtOutputOne < mPrevOutputOne) { mOutputOne->setLevel(--mPrevOutputOne); }
    
    if (mTgtOutputTwo > mPrevOutputTwo) { mOutputTwo->setLevel(++mPrevOutputTwo); }
    else if (mTgtOutputTwo < mPrevOutputTwo) { mOutputTwo->setLevel(--mPrevOutputTwo); }
}