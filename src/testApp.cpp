#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
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
    textWords = ofSplitString(text, " ");
    
    screenCenter = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
    offset = ofPoint(0, 0);
    scale = 1;
    
    placeWords(ofVec2f(0, 0));
    needsNewPlacement = true;
}

//--------------------------------------------------------------
void testApp::update(){
    
    if (needsNewPlacement) {
        
        ofVec2f start = words[0].getFirstVertice();
        ofRectangle bound = getWordsBoundingBox();
        ofVec2f diff = start - bound.getCenter();
        scale = 650 / max(bound.width, bound.height);
        placeWords(diff);
        needsNewPlacement = false;
    }
    
    bound = getWordsBoundingBox();

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofTranslate(screenCenter - bound.getCenter());
    ofScale(scale, scale);
    for (int i = 0; i < words.size(); i++) {
        ofSetColor(ofMap(i, 0, words.size() - 1 , 0, 230));
        words[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::placeWords(ofVec2f start){
    
    words.clear();
    words.push_back(Word(textWords[0], start, 0, characterIncrement, characters));
    
    float heading = 0;
    int space = 10;
    ofVec2f center = start;
    
    for (int i = 1; i < textWords.size(); i++) {
        
        Word lastWord = words[i - 1];
        heading = lastWord.getEndHeading(heading);
        
        ofVec2f offset(space * cos(ofDegToRad(heading)), space * sin(ofDegToRad(heading)));
        center = lastWord.getLastVertice() + offset;
        
        Word word = Word(textWords[i], center, heading, characterIncrement, characters);
        words.push_back(word);
        
    }
}

//--------------------------------------------------------------
ofRectangle testApp::getWordsBoundingBox(){
    
    ofRectangle container = words[0].getBoundingBox();
    for (int i = 1; i < words.size(); i++) {
        container = container.getUnion(words[i].getBoundingBox());
    }
    return container;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    int speed = 10;
    float scaleInterval = .025;
    
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
