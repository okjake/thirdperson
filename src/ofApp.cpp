#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    drawGUI = false;
    ofBackground(0,0,0);
    camIn.setup();
    vidIn.setup();
    audOut.setup("test/test.mp3");
    audOutTwo.setup("test/test2.mp3");
    map.setup(&vidIn, &audOut, &audOutTwo);
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    camIn.update();
    vidIn.update();
    audOut.update();
    audOutTwo.update();
    map.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (drawGUI) {
        camIn.drawGUI();
        vidIn.drawGUI();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        camIn.clear();
        vidIn.clear();
    }
    else if (key == 'f') {
        ofToggleFullscreen();
    }
    else if (key == 'g') {
        drawGUI = !drawGUI;
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
