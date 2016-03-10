#pragma once

#include "common.h"
#include "ofMain.h"
#include "cameraInput.h"
#include "videoInput.h"
#include "audioOutput.h"
#include "complimentaryMapper.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    
        bool drawGUI;
    
        cameraInput camIn;
        videoInput  vidIn;
        audioOutput audOut, audOutTwo;
    
        complimentaryMapper map;
};
