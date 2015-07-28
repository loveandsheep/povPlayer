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
	font = ofPtr<ofxFTGLFont>(new ofxFTGLFont);
	font->loadFont(fontPath, 10);
	
	currentTime = 0.0;
}

void SongData::update()
{
	
	if (isPlay)
	{
		currentTime = ofGetElapsedTimef() - startTime;
	}
	
	for (int i = 0;i < words.size();i++)
	{
		if (words[i]->update(currentTime) && words[i]->newLine)//新規ラインのワードが有効になった時
			for (int j = 0;j < words.size();j++)
			{
				if (words[j]->isViewing && words[j] != words[i])
					words[j]->disappear();//現在表示されてるワードを逃がす
			}
	}
	
}

void SongData::draw()
{
	for (int i = 0;i < words.size();i++) words[i]->draw();
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