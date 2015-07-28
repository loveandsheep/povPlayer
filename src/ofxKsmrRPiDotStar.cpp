//
//  ofxKsmrRPiDotStar.cpp
//  povPlayer
//
//  Created by Ovis aries on 2015/07/26.
//
//

#include "ofxKsmrRPiDotStar.h"

void ofxKsmrRPiDotStar::setup(int numLED)
{
	senderSig.assign(numLED * 4 + 8, 0x00);
	signal.assign(numLED * 4 + 8, 0x00);
	
	//フッタバイト挿入
	for (int i = 0;i < 4;i++)
		signal[numLED * 4 + 4 + i] = 0xFF;
	
	//初期化
	for (int i = 0;i < numLED;i++)
		setColor(i, 0, 0, 0);
	
#ifndef TARGET_OSX
	int speed = 100000;
	
	if ((wiringPiSPISetup (SPI_CHANNEL, speed)) < 0) {
		printf("wiringPiSPISetup error \n");
	}
	
	if (wiringPiSetupGpio() == -1)
	{
		printf("GPIO ERROR! \n");
	}
#endif

}

void ofxKsmrRPiDotStar::setColor(int channel, ofColor color)
{
	int targByte = 4 + channel * 4;
	
	signal[targByte		] = 0xFF;
	signal[targByte + 1	] = color.b;
	signal[targByte + 2 ] = color.g;
	signal[targByte + 3 ] = color.r;
	
}

void ofxKsmrRPiDotStar::setColor(int channel, int r, int g, int b)
{
	setColor(channel, ofColor(r, g, b));
}

void ofxKsmrRPiDotStar::show()
{
	memcpy(&senderSig[0], &signal[0], signal.size());
	
#ifndef TARGET_OSX
	wiringPiSPIDataRW(SPI_CHANNEL, &senderSig[0], senderSig.size());
#endif
	
}