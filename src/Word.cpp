//
//  Test.cpp
//  vectorPi_1
//
//  Created by bdorse on 3/27/14.
//
//

#include "Word.h"

Word::Word(string word, float angleIncrement, string characters){
    
    _lineLength = 25;
    _lineWidth = 1;
    _circleWidth = 5;
    
    _word = word;
    _characters = characters;
    _angleIncrement = angleIncrement;
    _polyline = ofPolyline();
    
    float angleInDegrees;
    
    for (int i = 0; i < _word.length(); i++) {
        
        int index = _characters.find(_word[i]);
        if (index != -1) {
            
            angleInDegrees = (index + 1) * _angleIncrement;
            _angles.push_back(angleInDegrees);
            
//            float x = 1 * cos(ofDegToRad(angleInDegrees));
//            float y = 1 * sin(ofDegToRad(angleInDegrees));
            
//            ofVec2f angle(x, y);
//            angle.normalize();
//            _angles.push_back(angle);
//            cout<<"Index: "<<_characters.find(_word[i])<<" Letter: "<<_word[i]<<endl;
//            cout<<"Angle in degrees: "<<angleInDegrees<<endl;
//            float rawAngle = ofVec2f(1, 0).angle(angle);
//            if (rawAngle <= 0) {
//                rawAngle = ofMap(rawAngle, 0, -180, 360, 180);
//            }
//            cout<<"Calculated angle with ofVec2f.angle: "<<rawAngle<<endl;
//            cout<<"atan2 in degrees: "<<ofRadToDeg(atan2(angle.x, angle.y))<<endl;
//            cout<<endl;
        }
    }
}

void Word::draw(ofVec2f start, float rotation){

    float angleSum = rotation;
    _polyline.clear();
    _polyline.addVertex(start);
    
    ofSetLineWidth(_lineWidth);
    ofFill();
    ofCircle(start, _circleWidth / 2);
    ofNoFill();
    
    ofVec2f point = start;
    
    for (int i = 0; i < _angles.size(); i++) {
        
        angleSum += _angles[i];
        float x = _lineLength * cos(ofDegToRad(angleSum));
        float y = _lineLength * sin(ofDegToRad(angleSum));
        
        ofVec2f angle(x, y);
        point += angle;
        _polyline.addVertex(point);

    }
    
    _polyline.draw();

}

float Word::getEndHeading(float rotation){
    
    float angleSum = rotation;
    for (int i = 0; i < _angles.size(); i++) {
        angleSum += _angles[i];
    }
    return angleSum;
}

ofVec2f Word::getFirstVertice(){
    vector<ofPoint> vertices = _polyline.getVertices();
    return vertices[0];
}

ofVec2f Word::getLastVertice(){
    vector<ofPoint> vertices = _polyline.getVertices();
    return vertices[vertices.size() - 1];
}

ofRectangle Word::getBoundingBox(){
    return _polyline.getBoundingBox();
}

