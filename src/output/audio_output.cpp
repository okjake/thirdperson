#include "audio_output.h"

void AudioOutput::setup(){
    setup("test/test.mp3");
}

void AudioOutput::setup(const char* filepath) {
    audio_.load(filepath);
    audio_.setVolume(0.0f);
    audio_.setMultiPlay(0);
    audio_.setLoop(true);
    audio_.play();
}

void AudioOutput::update(){
    ofSoundUpdate();
}

void AudioOutput::act() {
    
}

void AudioOutput::setLevel(short level) {
    audio_.setVolume(level*0.01f);
}