

#include "audioOutput.h"

void audioOutput::setup(){
    setup("test/test.mp3");
}

void audioOutput::setup(const char* filepath) {
    mTrack.loadSound(filepath);
    mTrack.setVolume(0.0f);
    mTrack.setMultiPlay(0);
    mTrack.setLoop(true);
    mTrack.play();
}

void audioOutput::update(){
    ofSoundUpdate();
}

void audioOutput::act() {
    
}

void audioOutput::setLevel(short level) {
    mTrack.setVolume(level*0.01f);
}