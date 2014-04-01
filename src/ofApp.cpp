#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableAntiAliasing();
    ofBackground(255);
    ofSetColor(0);
    ofSetLineWidth(1);
    ofNoFill();
    
    ofBuffer buffer = ofBufferFromFile("languages/english.txt");
    characters = buffer.getText();
    characterIncrement = float(360) / characters.length();
    
    buffer = ofBufferFromFile("writings/demo.txt");
    text = buffer.getText();
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);
    cout<<text<<endl;
    vector<string> textWords = ofSplitString(text, " ");
    
    offset = ofPoint(0, 0);
    scale = 1;
    
    int space = 50;
    int x = 0;
    int y = 0;

    for (int i = 0; i < textWords.size(); i++) {
        
        if ((i % 40 == 0) && (x != 0)){
            y += space;
            x = 0;
        }
        
        ofPoint start(x, y);
        Word word = Word(textWords[i], start, 0, characterIncrement, characters);
        words.push_back(word);
        
        x += space;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofRectangle container = getWordsBoundingBox();
    ofPoint center = container.getCenter();
//    float scale = ofGetWidth()/2 / max(container.width, container.height);
    
    ofPushMatrix();
    ofTranslate(offset);
    ofPushMatrix();
    ofTranslate(center.x, center.y);
    ofScale(scale, scale);
    for (int i = 0; i < words.size(); i++) {
        words[i].draw();
    }
    ofPopMatrix();
    ofPopMatrix();
}

//--------------------------------------------------------------
ofRectangle ofApp::getWordsBoundingBox(){
    ofRectangle container;
    for (int i = 0; i < words.size(); i++) {
        container = container.getUnion(words[i].getBoundingBox());
    }
    return container;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    int speed = 10;
    float scaleInterval = .2;
    
    if (key == OF_KEY_RIGHT) offset.x += speed;
    if (key == OF_KEY_LEFT) offset.x -= speed;
    if (key == OF_KEY_DOWN) offset.y += speed;
    if (key == OF_KEY_UP) offset.y -= speed;
    
    if (key == '-') scale -= scaleInterval;
    if (key == '=') scale += scaleInterval;
    
    if (key == ' '){
        ofSaveScreen("images/" + ofToString(ofGetUnixTime()) + ".png");
    }
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
