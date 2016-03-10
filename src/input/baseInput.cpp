#include "BaseInput.h"

using namespace ofxCv;

#define CAPTURE_WIDTH 320
#define CAPTURE_HEIGHT 240
#define CAPTURE_FRAME_RATE 30
#define SPOT_CENTER 160
#define SPOT_WIDTH 80

short BaseInput::sInputCount = 0;
short BaseInput::sSpotThreshLeft  = SPOT_CENTER - (SPOT_WIDTH / 2);
short BaseInput::sSpotThreshRight = SPOT_CENTER + (SPOT_WIDTH / 2);

void BaseInput::setup() {
    mSweetSpotOccupied = false;
    mMeanProxLHS = mMeanProxRHS = 0;
    openInputDevice(CAPTURE_WIDTH, CAPTURE_HEIGHT, CAPTURE_FRAME_RATE);
    img_.setFromPixels(mVid->getPixels(), CAPTURE_WIDTH, CAPTURE_HEIGHT, OF_IMAGE_COLOR);
    imitate(px_, img_);
    imitate(diff_, img_);
    ofEnableAlphaBlending();
}

void BaseInput::update() {
    mVid->update();
    if (mVid->isFrameNew()){
        img_.setFromPixels(mVid->getPixels(), 320, 240, OF_IMAGE_COLOR);
        
        absdiff(px_, img_, diff_);
        copy(img_, px_);
        
        mRunningBg.update(img_, thresh_);
        diff_.update();
        thresh_.update();
        
        if (bRecaptureBg) {
            mRunningBg.reset();
            bRecaptureBg = false;
        }
        
        ofPixels bgpx_;
        toOf(mRunningBg.getBackground(), bgpx_);
        bg_.setFromPixels(bgpx_);
        mContourFinder.findContours(thresh_);
        
        calculateMeanProximities();
    }
}

void BaseInput::drawGUI() {
    ofSetColor(255, 255, 255);
    img_.draw(0, mInputIndex * CAPTURE_HEIGHT);
    bg_.draw(CAPTURE_WIDTH, mInputIndex * CAPTURE_HEIGHT);
    thresh_.draw(2*CAPTURE_WIDTH, mInputIndex * CAPTURE_HEIGHT);
    diff_.draw(3*CAPTURE_WIDTH, mInputIndex * CAPTURE_HEIGHT);
    
    ofPushMatrix();
    ofTranslate(ofPoint(2*CAPTURE_WIDTH, mInputIndex * CAPTURE_HEIGHT));
    mContourFinder.draw();
    ofPopMatrix();
    
    ofSetColor(255, 255, 255, 100);
    ofDrawRectangle(sSpotThreshLeft, mInputIndex*CAPTURE_HEIGHT, SPOT_WIDTH, CAPTURE_HEIGHT);
    ofSetColor(255, 255, 255);
    ofDrawRectangle(SPOT_CENTER-1, mInputIndex*CAPTURE_HEIGHT, 2, CAPTURE_HEIGHT);
    
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
        
        ofDrawRectangle(center.x, mInputIndex * CAPTURE_HEIGHT, 5, repArea);
    }
}

void BaseInput::clear() {
    bRecaptureBg = true;
}

short BaseInput::getMeanProximity(SWEETSPOT_SECTOR sector) {

    if (sector == SECTOR_RIGHT) return mMeanProxRHS;
    return mMeanProxLHS;
}

/*
 * Helper function returns proximity to sweetspot as percentage
 */
short BaseInput::sweetSpotProximity(short position) {
    
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
bool BaseInput::isRHS(short position) {
    return position >= SPOT_CENTER;
};

/*
 * Calculate the mean proximity per sector
 */
void BaseInput::calculateMeanProximities() {
    
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

