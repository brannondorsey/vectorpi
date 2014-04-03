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
    vector<string> textWords = ofSplitString(text, " ");
    
    screenCenter = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
    offset = ofPoint(0, 0);
    scale = 1;
        
    for (int i = 0; i < textWords.size(); i++) {
        
        Word word = Word(textWords[i], characterIncrement, characters);
        words.push_back(word);
        
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
//    ofRectangle container = getWordsBoundingBox();
//    ofPoint center = container.getCenter();
//    float scale = ofGetWidth()/2 / max(container.width, container.height);
    //    ofTranslate(screenCenter - center);

    ofPushMatrix();
    ofTranslate(offset);
    render(ofRectangle(0,0,0,0));
    ofPopMatrix();
    
}

void testApp::render(ofRectangle bounding){
    
    float heading = 0;
    int space = 10;
    ofVec2f start(ofGetWidth()/2, ofGetHeight()/2);
    
    for (int i = 0; i < words.size(); i++) {
        
        ofVec2f center;
        
        if (i > 0) {
            Word lastWord = words[i - 1];
            heading = lastWord.getEndHeading();
            ofVec2f offset(space * cos(ofDegToRad(heading)), space * sin(ofDegToRad(heading)));
            center = lastWord.getLastVertice() + offset;
        } else center = start;

        
//        ofSetColor(ofMap(i, 0, words.size() - 1 , 0, 255));
        ofSetColor(0);
        words[i].draw(center, heading);
    }
}

//--------------------------------------------------------------
ofRectangle testApp::getWordsBoundingBox(){
    
    ofRectangle container = words[0].getBoundingBox();
    for (int i = 1; i < words.size(); i++) {
        container = container.getUnion(words[i].getBoundingBox());
//        cout<<container<<endl;
//        cout<<endl;
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
