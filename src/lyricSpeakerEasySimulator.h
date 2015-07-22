//
//  lyricSpeakerEasySimulator.h
//  musicSequence_proto
//
//  Created by Ovis aries on 2014/10/02.
//
//

#ifndef __musicSequence_proto__lyricSpeakerEasySimulator__
#define __musicSequence_proto__lyricSpeakerEasySimulator__

#include "ofMain.h"
#include "ofxOsc.h"

class lyricSpeakerEasySimulator{
public:
	void setup();
	void setMusic(string artist,string song);
	void play();
	void stop();

	string currentSong;
	string currentArtist;
	ofxOscSender sender;
};

#endif /* defined(__musicSequence_proto__lyricSpeakerEasySimulator__) */
