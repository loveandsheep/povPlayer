//
//  wordData.h
//  povPlayer
//
//  Created by Ovis aries on 2015/07/24.
//
//

#ifndef __povPlayer__wordData__
#define __povPlayer__wordData__

#include "ofMain.h"
#include "ofxFTGL.h"

class wordData
{
public:
	wordData()
	{
		finish = false;
		isViewing = false;
		scale = 1.0;
		zRot = 0.0;
	}
	
	ofPtr<ofxFTGLFont> fontPtr;
	string	word;
	ofVec2f pos;
	float	scale;
	float	zRot;
	float	time;
	bool	newLine;
	bool	isViewing;
	bool	finish;
	
	bool update(float currentTime);//出現時Bool返す
	void draw();
	void disappear();
};

#endif /* defined(__povPlayer__wordData__) */
