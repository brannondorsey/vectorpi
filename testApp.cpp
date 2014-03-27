#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    text = "why";
    lineLength = 150;
    
    ofEnableAntiAliasing();
    ofBackground(255);
    ofSetColor(0);
    ofSetLineWidth(3);
    ofNoFill();
    
    ofBuffer buffer = ofBufferFromFile("english.txt");
    characters = buffer.getText();
    int numCharacters = characters.length();
    characterIncrement = float(360) / numCharacters;
    
    float angleInDegrees;
    float rotationSum = 0;
    ofPoint translationSum(0, 0);
    
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
        
        rotationSum += angleInDegrees;
        cout<<"character: "<<text[i]<<" index: "<<characters.find(text[i])<<" angle: "<<angleInDegrees<<endl;
        float x = lineLength * cos(angleInDegrees);
        float y = lineLength * sin(angleInDegrees);
        // cout<<"x: "<<x<<" y: "<<y<<endl;
        polyline.addVertex(x, y);
        // translationSum += ofPoint(x, y);
        ofTranslate(x, y);
        ofRotate(angleInDegrees);

    }
    
//     ofTranslate(-translationSum.x, -translationSum.y);
//     ofRotate(-rotationSum);
    
    vector<ofPoint> vertices = polyline.getVertices();
    for (int i = 0; i < vertices.size(); i++) {
        // cout<<i<<": "<<vertices[i].x<<", "<<vertices[i].y<<endl;
    }
    
}

//--------------------------------------------------------------
void testApp::update(){

    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    // ofRect(0,0, 100, 100);
    polyline.draw();
    
    //cout<<endl;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
