#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	vMan.setup(64, 64);
	ofSetFrameRate(15);
}

//--------------------------------------------------------------
void ofApp::update(){
	vMan.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(20);
	
	vMan.buffer.begin();
	ofClear(0, 0, 0);

	ofSetColor(255);
	ofCircle(ofGetMouseX(), ofGetMouseY()+30, 30);
	vMan.buffer.end();
	
	vMan.sendBuffer();
	vMan.draw();
	vMan.drawBuf();
	vMan.testRec.draw(70,0);
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
