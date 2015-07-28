//
//  ofxKsmrRPiDotStar.h
//  povPlayer
//
//  Created by Ovis aries on 2015/07/26.
//
//

#ifndef __povPlayer__ofxKsmrRPiDotStar__
#define __povPlayer__ofxKsmrRPiDotStar__

#include "ofMain.h"
#include "ofxWiringPi.h"
#define SPI_CHANNEL 0

class ofxKsmrRPiDotStar{
public:
	
	void setup(int numLED);
	void setColor(int channel, ofColor color);
	void setColor(int channel, int r, int g, int b);
	void show();
	
protected:
	
	vector<unsigned char> signal;
	vector<unsigned char> senderSig;
	ofxWiringPi wpi;
	
};

#endif /* defined(__povPlayer__ofxKsmrRPiDotStar__) */
