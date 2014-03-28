//
//  Word.h
//  vectorPi_1
//
//  Created by bdorse on 3/27/14.
//
//

#ifndef vectorPi_1_Word_h
#define vectorPi_1_Word_h
#include "ofMain.h"

class Word{
    
    public:
    
        Word(ofPoint start, float rotation);
        void moveTo(int x, int y);
        void moveTo(ofPoint start);
        ofRectangle getBoundBox();
        float getEndHeading();
        void draw();
    
    protected:
    
        float rotation;
        ofPoint start;
        ofPolyline  polyline;

};

#endif
