//
//  Test.h
//  vectorPi_1
//
//  Created by bdorse on 3/27/14.
//
//

#ifndef vectorPi_1_Test_h
#define vectorPi_1_Test_h
#include "ofMain.h"

class Word{
public:
    
    ofPoint lastPoint;
    
    Word(string word, float angleIncrement, string characters);
    void draw(ofVec2f start, float rotation);
    void rotate(float rotation);
    float getEndHeading();
    ofVec2f getFirstVertice();
    ofRectangle getBoundingBox();
    ofVec2f getLastVertice();
    
protected:
    
    int _lineLength;
    int _lineWidth;
    float _circleWidth;
    float _angleIncrement;
    string _characters;
    string _word;
    vector<ofVec2f> _angles;
    
};


#endif
