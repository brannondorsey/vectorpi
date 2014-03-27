#pragma once

#include "ofMain.h"
#include "Word.h"

class testApp : public ofBaseApp{

	public:
        
        int lineLength;
        float characterIncrement; // e.g. 7 degrees
        string characters;
        string text;
        ofPoint startPoint;
        ofPoint nextPoint;
        ofPolyline polyline;
        vector<Word> words;
    
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
