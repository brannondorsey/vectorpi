#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    text = "onomatopoeia";
    lineLength = 150;
    
    ofEnableAntiAliasing();
    ofBackground(255);
    ofSetColor(0);
    ofSetLineWidth(1);
    ofNoFill();
    
    ofBuffer buffer = ofBufferFromFile("english.txt");
    characters = buffer.getText();
    int numCharacters = characters.length();
    characterIncrement = float(360) / numCharacters;
    
    float angleInDegrees;
    ofPoint translationSum(0, 0);
    ofPoint currentCenter(0, 0);
    float theta = 0;
    
    polyline = ofPolyline();
    polyline.addVertex(0, 0);

    
    /*
         Polar to Cartesian conversion: 
         float x = r * cos(theta);
         float y = r * sin(theta);
     
        For each letter:
            1. calculate polar coordinates (radius, theta)
            2. convert to cartesian coordinates
            3. lineTo cartesian coordinates
            4. rotate world to re-orient polar coordinates as 0 degrees
     */
     
    
    for (int i = 0; i < text.length(); i++) {
        
        int index = characters.find(text[i]);
        
        if (index != -1) {
            
            angleInDegrees = (index + 1) * characterIncrement;
            
        } else {
            //space
        }
        
        theta += angleInDegrees;
        
        float x = lineLength * cos(ofDegToRad(theta));
        float y = lineLength * sin(ofDegToRad(theta));
        
        cout<<"character: "<<text[i]<<" index: "<<characters.find(text[i])<<" angle: "<<angleInDegrees<<
        " x: "<<x<<" y: "<<y<<endl;
        polyline.addVertex(currentCenter + ofPoint(x, y));
        
        currentCenter += ofPoint(x, y);

    }
    
    vector<ofPoint> vertices = polyline.getVertices();
    for (int i = 0; i < vertices.size(); i++) {
        // cout<<i<<": "<<vertices[i].x<<", "<<vertices[i].y<<endl;
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRectangle bound = polyline.getBoundingBox();
    
    float scale = 100 / max(bound.width, bound.height);
    ofScale(scale, scale);
    polyline.draw();
    

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
