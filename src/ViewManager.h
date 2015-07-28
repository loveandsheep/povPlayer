//
//  ViewManager.h
//  povPlayer
//
//  Created by Ovis aries on 2015/07/17.
//
//

#ifndef __povPlayer__ViewManager__
#define __povPlayer__ViewManager__

#include "ofMain.h"
#include "ofxKsmrRPiDotStar.h"

class viewManager{
public:
	
	void setup(int w, int h);
	void update();
	void draw();
	void drawBuf();
	
	void sendBuffer();
	void test_receive(unsigned char* buf, int num);
	
	ofFbo buffer;
	
	ofSerial serial;
	ofImage testRec;
	
	ofPixels pix;
	int targetLine;
	ofxKsmrRPiDotStar dotstar;
};

#endif /* defined(__povPlayer__ViewManager__) */
