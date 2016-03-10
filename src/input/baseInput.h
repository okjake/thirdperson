
/*
 * Base class for inputs
 *
 * - Contains video processing logic to extract proximity of participants to the sweet spot
 * - To add a new input inherit from this class and implement the openInputDevice method (see videoInput)
 */

#ifndef __sweetspot__baseInput__
#define __sweetspot__baseInput__

#include "common.h"
#include "ofxCv.h"

class baseInput {
  
    public:
        baseInput() { mInputIndex = sInputCount++; }
        ~baseInput(){ sInputCount--; }
    
        baseInput(const baseInput&) { sInputCount++; }

        void setup();
        void update();
        void clear();
        void drawGUI();
    
        short getMeanProximity(SWEETSPOT_SECTOR sector);
        bool  isSweetSpotOccupied(){ return mSweetSpotOccupied; }
        virtual void openInputDevice(short captureWidth, short captureHeight, short captureRate) = 0;
    
    protected:
    
        short sweetSpotProximity(short position);
        bool  isRHS(short position);
        void  calculateMeanProximities();

        static short sInputCount, sSpotThreshLeft, sSpotThreshRight;
    
        ofImage  mImg, mDiff, mThresh, mBg;
        ofPixels mPixels;
    
        bool         bRecaptureBg, mSweetSpotOccupied;
        unsigned int mInputIndex,  mMeanProxLHS, mMeanProxRHS;
    
        ofxCv::RunningBackground mRunningBg;
        ofxCv::ContourFinder     mContourFinder;
    
        ofBaseVideoDraws *mVid;

};

#endif /* defined(__sweetspot__baseInput__) */
