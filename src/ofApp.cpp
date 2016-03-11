#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    
    draw_gui_ = false;
    ofBackground(0,0,0);
    
    inputs.one = new CameraInput();
    inputs.one->setup();
    
    inputs.two = new VideoInput();
    inputs.two->setup();
    
    outputs.one = new AudioOutput();
    outputs.one->setup();
    
    outputs.two = new AudioOutput();
    outputs.two->setup();

    map.setup(inputs.two, outputs.one, outputs.two);
}

//--------------------------------------------------------------
void ofApp::update(){
    inputs.one->update();
    inputs.two->update();
    outputs.one->update();
    outputs.two->update();
    map.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (draw_gui_) {
        inputs.one->drawGUI();
        inputs.two->drawGUI();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        inputs.one->clear();
        inputs.two->clear();
    }
    else if (key == 'f') {
        ofToggleFullscreen();
    }
    else if (key == 'g') {
        draw_gui_ = !draw_gui_;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
