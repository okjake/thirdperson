#include "linearMapper.h"

void linearMapper::setup(baseInput *input, baseOutput *output, SWEETSPOT_SECTOR sector) {
    mInput = input;
    mOutput = output;
    mTgtOutput = mPrevOutput = 0;
    mSector = sector;
}

void linearMapper::update() {
    
    if (mInput->isSweetSpotOccupied()) {
        mTgtOutput = 100;
    }
    else {
        mTgtOutput = mInput->getMeanProximity(mSector);
    }
    
    if (mTgtOutput > mPrevOutput) {
        mOutput->setLevel(++mPrevOutput);
    }
    else if (mTgtOutput < mPrevOutput) {
        mOutput->setLevel(--mPrevOutput);
    }
    
}