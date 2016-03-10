
/*
 * Base class for inputs
 *
 * - Contains video processing logic to extract proximity of participants to the sweet spot
 * - To add a new input inherit from this class and implement the openInputDevice method (see videoInput)
 */

#ifndef thirdperson_baseinput
#define thirdperson_baseinput

#include "Common.h"
#include "ofxCv.h"

class BaseInput {
  
    public:
        BaseInput() { input_idx_ = input_count_++; }
        ~BaseInput(){ sInputCount--; }
    
        BaseInput(const BaseInput&) { sInputCount++; }

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
    
    ofImage img_;
    ofImage diff_;
    ofImage thresh_;
    ofImage bg_;
    ofPixels px_;
    
        bool         bRecaptureBg, mSweetSpotOccupied;
        unsigned int mInputIndex,  mMeanProxLHS, mMeanProxRHS;
    
        ofxCv::RunningBackground mRunningBg;
        ofxCv::ContourFinder     mContourFinder;
    
        ofBaseVideoDraws *vid_;

};

#endif
