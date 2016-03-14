#include "BaseInput.h"

using namespace ofxCv;

#define CAPTURE_WIDTH 320
#define CAPTURE_HEIGHT 240
#define CAPTURE_FRAME_RATE 30
#define SPOT_CENTER 160
#define SPOT_WIDTH 80

short BaseInput::count_instance_ = 0;

void BaseInput::setup() {
    spot_threshold_.left   = SPOT_CENTER - (SPOT_WIDTH / 2);
    spot_threshold_.right  = SPOT_CENTER + (SPOT_WIDTH / 2);
    mean_proximities_.left = mean_proximities_.right = 0;
    spot_occupied_ = false;
    
    openInputDevice(CAPTURE_WIDTH, CAPTURE_HEIGHT, CAPTURE_FRAME_RATE);
    img_.setFromPixels(feed_->getPixels(), CAPTURE_WIDTH, CAPTURE_HEIGHT, OF_IMAGE_COLOR);
    
    imitate(px_, img_);
    imitate(diff_, img_);
}

void BaseInput::update() {
    
    feed_->update();
    
    if (feed_->isFrameNew()){
        img_.setFromPixels(feed_->getPixels(), 320, 240, OF_IMAGE_COLOR);
        
        absdiff(px_, img_, diff_);
        copy(img_, px_);
        
        running_background_.update(img_, thresh_);
        diff_.update();
        thresh_.update();
        
        if (recapture_background_) {
            running_background_.reset();
            recapture_background_ = false;
        }
        
        ofPixels bgpx_;
        toOf(running_background_.getBackground(), bgpx_);
        bg_.setFromPixels(bgpx_);
        contour_finder_.findContours(thresh_);
        
        calculateMeanProximities();
    }
}

void BaseInput::drawGUI() {
    ofSetColor(255, 255, 255);
    
    img_.draw(0, index_instance_ * CAPTURE_HEIGHT);
    bg_.draw(CAPTURE_WIDTH, index_instance_ * CAPTURE_HEIGHT);
    thresh_.draw(2*CAPTURE_WIDTH, index_instance_ * CAPTURE_HEIGHT);
    diff_.draw(3*CAPTURE_WIDTH, index_instance_ * CAPTURE_HEIGHT);
    
    ofPushMatrix();
    ofTranslate(ofPoint(2*CAPTURE_WIDTH, index_instance_ * CAPTURE_HEIGHT));
    contour_finder_.draw();
    ofPopMatrix();
    
    ofSetColor(255, 255, 255, 100);
    ofDrawRectangle(spot_threshold_.left, index_instance_ * CAPTURE_HEIGHT, SPOT_WIDTH, CAPTURE_HEIGHT);
    ofSetColor(255, 255, 255);
    ofDrawRectangle(SPOT_CENTER-1, index_instance_ * CAPTURE_HEIGHT, 2, CAPTURE_HEIGHT);
    
    for (int i=0; i < contour_finder_.size(); i++){
        cv::Point2f center = contour_finder_.getCenter(i);
        unsigned short proximity = sweetSpotProximity(center.x);
        
        if (proximity != 100) {
            ofSetColor(proximity, 255, proximity);
        } else {
            ofSetColor(255, 255, 255);
        }
        
        float repArea = 0.05 * (int)contour_finder_.getContourArea(i);
        if (repArea > CAPTURE_HEIGHT) repArea = CAPTURE_HEIGHT;
        
        ofDrawRectangle(center.x, index_instance_ * CAPTURE_HEIGHT, 5, repArea);
    }
}

void BaseInput::clear() {
    recapture_background_ = true;
}

short BaseInput::meanProximity(SWEETSPOT_SECTOR sector) {

    if (sector == SECTOR_RIGHT) return mean_proximities_.right;
    return mean_proximities_.left;
}

/*
 * Helper function returns proximity to sweetspot as percentage
 */
short BaseInput::sweetSpotProximity(short position) {
    
    if (position < spot_threshold_.left) {
        return ((100.0 / spot_threshold_.left) * position);
    }
    else if (position > spot_threshold_.right) {
        float space = CAPTURE_WIDTH - spot_threshold_.right;
        return (100.0 / space) * (space - (position - spot_threshold_.right));
    }
    
    return 100;
}


/* 
 * Find out which sector the position is in
 */
bool BaseInput::isRHS(short position) {
    return position >= SPOT_CENTER;
};


// Calculate the mean proximity per sector
void BaseInput::calculateMeanProximities() {
    
    LRPair count;
    LRPair total;
    count.left = count.right = 0;
    total.left = total.right = 0;
    spot_occupied_ = false;
    
    for (int i=0; i < contour_finder_.size(); i++){
        cv::Point2f center = contour_finder_.getCenter(i);
        
        // Set the occupied flag if they are in the sweet spot
        if (spot_threshold_.left <= center.x && center.x <= spot_threshold_.right) {
            spot_occupied_ = true;
        }
        
        if (isRHS(center.x)) {
            count.right++;
            total.right += sweetSpotProximity(center.x);
        } else {
            count.left++;
            total.left += sweetSpotProximity(center.x);
        }
    }
    
    mean_proximities_.left  = count.left  ? (total.left  / count.left ) : 0;
    mean_proximities_.right = count.right ? (total.right / count.right) : 0;

}

