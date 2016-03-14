#pragma once

#include "ofMain.h"
#include "common.h"
#include "camera_input.h"
#include "video_input.h"
#include "audio_output.h"
#include "complimentary_mapper.h"

struct InputPair {
    BaseInput *one;
    BaseInput *two;
};

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

    
        bool draw_gui_;
    
        InputPair  inputs;
        OutputPair outputs;
    
        ComplimentaryMapper map;
};
