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
    
    Word(const std::string& word,
         float rotation,
         float angleIncrement,
         const std::string& characters);

    //    void setup(string word, ofPoint start, float rotation, float angleIncrement, string characters);
    void draw(const ofPoint& start);
    void rotate(float rotation);
    void moveTo(const ofPoint& start);
    void fitTo(float size);
    void scaleWidthTo(float size);
    void scaleHeightTo(float size);
    float getEndHeading();
    ofPoint getFirstVertice(); // TODO: vertex?
    ofRectangle getBoundingBox();
    ofPoint getLastVertice();
    
protected:
    
    int _lineLength;
    int _lineWidth;
    float _theta;
    float _circleWidth;
    float _angleIncrement;
    float _rotation;
    ofPolyline _polyline;
    std::string _characters;
    std::string _word;
    
};


#endif
