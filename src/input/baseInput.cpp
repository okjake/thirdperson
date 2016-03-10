#include "baseInput.h"

using namespace ofxCv;

#define CAPTURE_WIDTH 320
#define CAPTURE_HEIGHT 240
#define CAPTURE_FRAME_RATE 30
#define SPOT_CENTER 160
#define SPOT_WIDTH 80

short baseInput::sInputCount = 0;
short baseInput::sSpotThreshLeft  = SPOT_CENTER - (SPOT_WIDTH / 2);
short baseInput::sSpotThreshRight = SPOT_CENTER + (SPOT_WIDTH / 2);

void baseInput::setup() {
    mSweetSpotOccupied = false;
    mMeanProxLHS = mMeanProxRHS = 0;
    openInputDevice(CAPTURE_WIDTH, CAPTURE_HEIGHT, CAPTURE_FRAME_RATE);
    mImg.setFromPixels(mVid->getPixels(), CAPTURE_WIDTH, CAPTURE_HEIGHT, OF_IMAGE_COLOR);
    imitate(mPixels, mImg);
    imitate(mDiff, mImg);
    ofEnableAlphaBlending();
}

void baseInput::update() {
    mVid->update();
    if (mVid->isFrameNew()){
        mImg.setFromPixels(mVid->getPixels(), 320, 240, OF_IMAGE_COLOR);
        
        absdiff(mPixels, mImg, mDiff);
        copy(mImg, mPixels);
        
        mRunningBg.update(mImg, mThresh);
        mDiff.update();
        mThresh.update();
        
        if (bRecaptureBg) {
            mRunningBg.reset();
            bRecaptureBg = false;
        }
        
        ofPixels mPixelsBg;
        toOf(mRunningBg.getBackground(), mPixelsBg);
        mBg.setFromPixels(mPixelsBg);
        mContourFinder.findContours(mThresh);
        
        calculateMeanProximities();
    }
}

void baseInput::drawGUI() {
    ofSetColor(255, 255, 255);
    mImg.draw(0, mInputIndex * CAPTURE_HEIGHT);
    mBg.draw(CAPTURE_WIDTH, mInputIndex * CAPTURE_HEIGHT);
    mThresh.draw(2*CAPTURE_WIDTH, mInputIndex * CAPTURE_HEIGHT);
    mDiff.draw(3*CAPTURE_WIDTH, mInputIndex * CAPTURE_HEIGHT);
    
    ofPushMatrix();
    ofTranslate(ofPoint(2*CAPTURE_WIDTH, mInputIndex * CAPTURE_HEIGHT));
    mContourFinder.draw();
    ofPopMatrix();
    
    ofSetColor(255, 255, 255, 100);
    ofRect(sSpotThreshLeft, mInputIndex*CAPTURE_HEIGHT, SPOT_WIDTH, CAPTURE_HEIGHT);
    ofSetColor(255, 255, 255);
    ofRect(SPOT_CENTER-1, mInputIndex*CAPTURE_HEIGHT, 2, CAPTURE_HEIGHT);
    
    for (int i=0; i < mContourFinder.size(); i++){
        cv::Point2f center = mContourFinder.getCenter(i);
        unsigned short proximity = sweetSpotProximity(center.x);
        
        if (proximity != 100) {
            ofSetColor(proximity, 255, proximity);
        } else {
            ofSetColor(255, 255, 255);
        }
        
        float repArea = 0.05 * (int)mContourFinder.getContourArea(i);
        if (repArea > CAPTURE_HEIGHT) repArea = CAPTURE_HEIGHT; // TODO hacky
        
        ofRect(center.x, mInputIndex * CAPTURE_HEIGHT, 5, repArea);
    }
}

void baseInput::clear() {
    bRecaptureBg = true;
}

short baseInput::getMeanProximity(SWEETSPOT_SECTOR sector) {

    if (sector == SECTOR_RIGHT) return mMeanProxRHS;
    return mMeanProxLHS;
}

/*
 * Helper function returns proximity to sweetspot as percentage
 */
short baseInput::sweetSpotProximity(short position) {
    
    if (position < sSpotThreshLeft) {
        return ((100.0 / sSpotThreshLeft) * position);
    }
    else if (position > sSpotThreshRight) {
        float space = CAPTURE_WIDTH - sSpotThreshRight;
        return (100.0 / space) * (space - (position - sSpotThreshRight));
    }
    
    return 100;
}


/* 
 * Find out which sector the position is in
 */
bool baseInput::isRHS(short position) {
    return position >= SPOT_CENTER;
};

/*
 * Calculate the mean proximity per sector
 */
void baseInput::calculateMeanProximities() {
    
    unsigned int countLHS = 0, totalLHS = 0 , countRHS = 0, totalRHS = 0;
    mSweetSpotOccupied = false;
    
    for (int i=0; i < mContourFinder.size(); i++){
        cv::Point2f center = mContourFinder.getCenter(i);
        
        // Set the occupied flag if they are in the sweet spot
        if (sSpotThreshLeft <= center.x && center.x <= sSpotThreshRight) {
            mSweetSpotOccupied = true;
        }
        
        if (isRHS(center.x)) {
            countRHS++;
            totalRHS += sweetSpotProximity(center.x);
        } else {
            countLHS++;
            totalLHS += sweetSpotProximity(center.x);
        }
    }
    
    if (countLHS)
        mMeanProxLHS = (totalLHS/countLHS);
    else
        mMeanProxLHS = 0;

    if (countRHS)
        mMeanProxRHS = (totalRHS/countRHS);
    else
        mMeanProxRHS = 0;

}

