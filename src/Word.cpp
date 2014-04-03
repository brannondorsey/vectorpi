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
    
    float angleInDegrees;
    
    for (int i = 0; i < _word.length(); i++) {
        
        int index = _characters.find(_word[i]);
        if (index != -1) {
            
            angleInDegrees = (index + 1) * _angleIncrement;
            
            float x = 1 * cos(ofDegToRad(angleInDegrees));
            float y = 1 * sin(ofDegToRad(angleInDegrees));
            
            ofVec2f angle(x, y);
            angle.normalize();
            _angles.push_back(angle);
            cout<<"Index: "<<_characters.find(_word[i])<<" Letter: "<<_word[i]<<endl;
            cout<<"Angle in degrees: "<<angleInDegrees<<endl;
//            cout<<"Calculated angle with ofVec2f.angle: "<<angle.angle(ofVec2f(0, 0))<<endl;
//            cout<<"atan2 in degrees: "<<ofRadToDeg(atan2(angle.x, angle.y))<<endl;
            cout<<endl;
        }
    }
}

void Word::draw(ofVec2f start, float rotation){

    
    ofPolyline polyline;
    start.rotate(rotation);
    
    // start.scale(_lineLength);
    polyline.addVertex(start);
    
    ofSetLineWidth(_lineWidth);
    ofFill();
    ofCircle(start, _circleWidth / 2);
    ofNoFill();
    
    ofVec2f point = start;
    
    for (int i = 1; i < _angles.size(); i++) {
        ofVec2f angle = _angles[i];
        ofVec2f prevAngle = _angles[i - 1];
        angle.rotate(angle.angle(prevAngle));
        angle.scale(_lineLength);
        point += angle;
        polyline.addVertex(point);
//        cout<<point<<endl;
    }
//    cout<<endl;
    
    polyline.draw();

}

float Word::getEndHeading(){
    
    ofVec2f secondToLast = _angles[_angles.size() - 2];
    ofVec2f last = _angles[_angles.size() - 1];
    return secondToLast.angle(last);
}

ofVec2f Word::getFirstVertice(){
    return _angles[0];
}

ofVec2f Word::getLastVertice(){
    return _angles[_angles.size() - 1];
}

ofRectangle Word::getBoundingBox(){

}

