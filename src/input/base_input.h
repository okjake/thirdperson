
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
    BaseInput() { index_instance_ = count_instance_++; }
    ~BaseInput(){ count_instance_--; }

    BaseInput(const BaseInput&) { count_instance_++; }

    void setup();
    void update();
    void clear();
    void drawGUI();

    short meanProximity(SWEETSPOT_SECTOR sector);
    bool  sweetSpotOccupied(){ return spot_occupied_; }
    
    virtual void openInputDevice(short cap_width, short cap_height, short cap_rate) = 0;
    
protected:
    
    short sweetSpotProximity(short position);
    bool  isRHS(short position);
    void  calculateMeanProximities();

    static short count_instance_;
    unsigned int index_instance_;
    
    ofImage img_;
    ofImage diff_;
    ofImage thresh_;
    ofImage bg_;
    ofPixels px_;
    
    bool spot_occupied_;
    bool recapture_background_;
    
    LRPair spot_threshold_;
    LRPair mean_proximities_;
    
    ofxCv::RunningBackground running_background_;
    ofxCv::ContourFinder     contour_finder_;
    
    ofBaseVideoDraws *feed_;

};

#endif
