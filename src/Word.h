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
         ofVec2f start,
         float rotation,
         float angleIncrement,
         const std::string& characters);
    void draw();
    float getEndHeading(const float& rotation);
    ofVec2f getFirstVertice();
    ofRectangle getBoundingBox();
    ofVec2f getLastVertice();
    
protected:
    
    int _lineLength;
    int _lineWidth;
    float _circleWidth;
    float _angleIncrement;
    std::string _characters;
    std::string _word;
    std::vector<float> _angles;
    ofPolyline _polyline;
    
};


#endif
