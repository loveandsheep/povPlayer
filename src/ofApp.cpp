#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	
	vMan.setup(64, 64);
	songMan.setup();
}

//--------------------------------------------------------------
void ofApp::update()
{
	songMan.update();
	vMan.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(20);
	
	vMan.buffer.begin();
	{
		ofClear(0, 0, 0);
		
		ofSetColor(255, 0, 0);
		ofCircle(ofGetMouseX(), ofGetMouseY(), 30);
		ofSetColor(0, 0, 255);
		ofCircle(ofGetMouseY(), ofGetMouseX(), 20);
		
		songMan.draw();
	}
	vMan.buffer.end();
	
	ofSetColor(255);
	vMan.drawBuf();
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
