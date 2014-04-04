//
//  Test.cpp
//  vectorPi_1
//
//  Created by bdorse on 3/27/14.
//
//

#include "Word.h"

Word::Word(const std::string& word,
           ofVec2f start,
           float rotation,
           float angleIncrement,
           const std::string& characters):
_lineLength(24),
_lineWidth(1),
_circleWidth(5),
_word(word),
_characters(characters),
_angleIncrement(angleIncrement),
_polyline(ofPolyline())
{
    float angleInDegrees = 0;
    
    for (int i = 0; i < _word.length(); i++) {
        
        int index = _characters.find(_word[i]);
        if (index != -1) {
            
            angleInDegrees = (index + 1) * _angleIncrement;
            _angles.push_back(angleInDegrees);
        
        }
    }
    
    
    float angleSum = rotation;
    _polyline.addVertex(start);
    ofVec2f center = start;
    
    for (int i = 0; i < _angles.size(); i++) {
      
        angleSum += _angles[i];
        float x = _lineLength * cos(ofDegToRad(angleSum));
        float y = _lineLength * sin(ofDegToRad(angleSum));
        
        ofVec2f angle(x, y);
        center += angle;
        _polyline.addVertex(center);
        
    }
}

void Word::draw(){

    ofSetLineWidth(_lineWidth);
    ofFill();
    ofCircle(getFirstVertice(), _circleWidth / 2);
    ofNoFill();
    _polyline.draw();

}

float Word::getEndHeading(const float& rotation){
    
    float angleSum = rotation;
    for (int i = 0; i < _angles.size(); i++) {
        angleSum += _angles[i];
    }
    return angleSum;
}

ofVec2f Word::getFirstVertice(){
    return _polyline[0];
}

ofVec2f Word::getLastVertice(){
    return _polyline[_polyline.size() - 1];
}

ofRectangle Word::getBoundingBox(){
    return _polyline.getBoundingBox();
}

