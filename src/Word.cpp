//
//  Test.cpp
//  vectorPi_1
//
//  Created by bdorse on 3/27/14.
//
//

#include "Word.h"

Word::Word(string word, ofPoint start, float rotation, float angleIncrement, string characters){
    
    _lineLength = 25;
    _lineWidth = 1;
    _circleWidth = 5;
    
    _word = word;
    _characters = characters;
    _rotation = rotation;
    _angleIncrement = angleIncrement;
    _polyline = ofPolyline();
    _polyline.addVertex(start);
    
    float angleInDegrees;
    float theta;
    
    ofPoint center = start;
    
    for (int i = 0; i < _word.length(); i++) {
        
        int index = _characters.find(_word[i]);
        
        if (index != -1) {
            
            angleInDegrees = (index + 1) * _angleIncrement;
            
        }
        
        theta += angleInDegrees;
        
        float x = _lineLength * cos(ofDegToRad(theta));
        float y = _lineLength * sin(ofDegToRad(theta));
        
        _polyline.addVertex(center + ofPoint(x, y));
        
        center += ofPoint(x, y);
        
    }
}

void Word::draw(){
    
    ofSetLineWidth(_lineWidth);
    ofPushMatrix();
    ofRotate(_rotation);
    ofFill();
    ofCircle(getFirstVertice(), _circleWidth / 2);
    ofNoFill();
    _polyline.draw();
    ofPopMatrix();
}

void Word::rotate(float rotation){
    _rotation += rotation;
}

void Word::moveTo(ofPoint start){
    
}

void Word::fitTo(float size){
    
//    ofRectangle bound = _polyline.getBoundingBox();
//    float scale = size / max(bound.width, bound.height);
//    ofScale(scale, scale);
}

float Word::getEndHeading(){
    
}

ofPoint Word::getFirstVertice(){
    vector<ofPoint> vertices = _polyline.getVertices();
    return vertices[0];
}

ofPoint Word::getLastVertice(){
    vector<ofPoint> vertices = _polyline.getVertices();
    return vertices[vertices.size() - 1];
}

ofRectangle Word::getBoundingBox(){
    return _polyline.getBoundingBox();
}

