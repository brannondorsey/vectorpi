#pragma once

#include "ofMain.h"
#include "Word.h"

class testApp : public ofBaseApp{

	public:
        
        int lineLength;
        float scale;
        float characterIncrement; // e.g. 7 degrees
        bool needsNewPlacement;
        string characters;
        string text;
        ofPoint startPoint;
        ofPoint nextPoint;
        ofPoint offset;
        ofPoint screenCenter;
        ofRectangle bound;
        ofPolyline polyline;
        vector<string> textWords;
        vector<Word> words;
    
		void setup();
		void update();
		void draw();
        void placeWords(ofVec2f start);
        ofRectangle getWordsBoundingBox();
        
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
