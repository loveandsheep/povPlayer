//
//  SongData.h
//  povPlayer
//
//  Created by Ovis aries on 2015/07/17.
//
//

#ifndef __povPlayer__SongData__
#define __povPlayer__SongData__

#include "ofMain.h"
#include "wordData.h"
#include "ofxTrueTypeFontUC.h"

class SongData{
public:
	
	void setup(string fontPath);
	void update();
	void draw();
	void setWord(float time, string word, ofVec2f pos, bool isNewLine);

	void play();

	bool isPlay;
	
	float startTime;
	float currentTime;
	vector< ofPtr<wordData> > words;
	ofPtr<ofxTrueTypeFontUC> font;
	
};

#endif /* defined(__povPlayer__SongData__) */
