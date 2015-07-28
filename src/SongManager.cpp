//
//  SongManager.cpp
//  povPlayer
//
//  Created by Ovis aries on 2015/07/24.
//
//

#include "SongManager.h"

void SongManager::setup()
{
	testSong.setup("hiraginokaku.otf");
	testSong.setWord(1.0, "テスト"		, ofVec2f(32,32), false);
	testSong.setWord(2.0, "都テスト"		, ofVec2f(32,32), false);
	testSong.setWord(3.0, "新規"			, ofVec2f(32,32), true);
	testSong.setWord(4.0, "りんいなasa"	, ofVec2f(32,32), false);
}

void SongManager::update()
{
	if (ofGetKeyPressed(' ')) testSong.play();
	testSong.update();
}

void SongManager::draw()
{
	testSong.draw();
}