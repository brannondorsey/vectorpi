//
//  Test.cpp
//  vectorPi_1
//
//  Created by bdorse on 3/27/14.
//
//

#include "Word.h"

Word::Word(const std::string& word,
           float rotation,
           float angleIncrement,
           const std::string& characters):
    _lineLength(24),
    _lineWidth(1),
    _circleWidth(5),
    _theta(0),
    _word(word),
    _characters(characters),
    _angleIncrement(angleIncrement),
    _polyline(ofPolyline())
{
    ofPoint center(0, 0);
    _polyline.addVertex(center);
    
    float angleInDegrees = 0;
    
    for (int i = 0; i < _word.length(); i++) {
        
        int index = _characters.find(_word[i]);
        
        if (index != -1) {
            
            angleInDegrees = (index + 1) * _angleIncrement;
            
        }
        
        _theta += angleInDegrees;
        
        float x = _lineLength * cos(ofDegToRad(_theta));
        float y = _lineLength * sin(ofDegToRad(_theta));
        
        _polyline.addVertex(center + ofPoint(x, y));
        
        center += ofPoint(x, y);
    }
}

void Word::draw(const ofPoint& start){
    
    ofSetLineWidth(_lineWidth);
//    ofPushMatrix();
//    ofTranslate(start);
//    ofRotate(_rotation);
    ofFill();
    ofCircle(getFirstVertice(), _circleWidth / 2);
    ofNoFill();
    _polyline.draw();
//    ofPopMatrix();
}

void Word::rotate(float rotation){
    _rotation += rotation;
}

void Word::moveTo(const ofPoint& start){
    
}

void Word::fitTo(float size){
    
//    ofRectangle bound = _polyline.getBoundingBox();
//    float scale = size / max(bound.width, bound.height);
//    ofScale(scale, scale);
}

float Word::getEndHeading(){
    
//    vector<ofPoint> vertices = _polyline.getVertices();
//    ofPoint secondToLast = vertices[vertices.size() - 2];
//    ofPoint last = vertices[vertices.size() - 1];
//    return secondToLast.angle(last);
    return _theta;
}

ofPoint Word::getFirstVertice(){
    return _polyline[0];
}

ofPoint Word::getLastVertice(){
    return _polyline[_polyline.size() - 1];
}

ofRectangle Word::getBoundingBox(){
    return _polyline.getBoundingBox();
}

