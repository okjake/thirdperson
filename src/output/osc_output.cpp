#include "osc_output.h"

void OscOutput::setup(){
}

void OscOutput::update(){
}

void OscOutput::act() {
    ofxOscMessage m;
    m.setAddress("/test");
    m.addIntArg(level_);
    sender_.sendMessage(m);
}

void OscOutput::setLevel(short level) {
    level_ = level;
}