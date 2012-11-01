#include "testApp.h"

int x = 100;

//--------------------------------------------------------------
void testApp::setup(){
    screen.setIpServer("192.168.0.200");
    screen.setupSend();
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    //ofScale(10, 10);
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 0, 127);
    ofRect(10, 10, 20, 20);
    ofSetColor(255, 0, 255, 127);
    ofRect(15, 15, 20, 20);
    screen.captureScreen(0, 0);
    screen.flush();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

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