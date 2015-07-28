//
//  SongData.cpp
//  povPlayer
//
//  Created by Ovis aries on 2015/07/17.
//
//

#include "SongData.h"

void SongData::setup(string fontPath)
{
	font = ofPtr<ofxTrueTypeFontUC>(new ofxTrueTypeFontUC);
	font->loadFont(fontPath, 10);
	
	currentTime = 0.0;
}

void SongData::update()
{
	
	if (isPlay)
	{
		currentTime = ofGetElapsedTimef() - startTime;
	}
	
	for (auto it : words)
	{
		if (it->update(currentTime) && it->newLine)//新規ラインのワードが有効になった時
			for (auto rm : words)
				if (rm->isViewing && rm != it) rm->disappear();//現在表示されてるワードを逃がす
	}
}

void SongData::draw()
{
	for (auto it : words) it->draw();
}

void SongData::setWord(float time, string word, ofVec2f pos, bool isNewLine)
{
	ofPtr<wordData> nwd = ofPtr<wordData>(new wordData);
	nwd->time = time;
	nwd->word = word;
	nwd->newLine = isNewLine;
	nwd->fontPtr = font;
	nwd->pos = pos;
	
	words.push_back(nwd);
}

void SongData::play()
{
	isPlay = true;
	startTime = ofGetElapsedTimef();
}