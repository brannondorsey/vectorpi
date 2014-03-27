//
//  Word.h
//  vectorPi_1
//
//  Created by bdorse on 3/27/14.
//
//

#ifndef vectorPi_1_Word_h
#define vectorPi_1_Word_h
# include "ofMain.h"

class Word{
    
    public:
    
        Word(int x, int y, float rotation);
        Word(ofPoint start, float rotation);
        ofRectangle getBoundBox();
        float getEndHeading();
        void draw();
    
    protected:
    
        float rotation;
        ofPoint start;

};

#endif
