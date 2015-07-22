//
//  lyricSpeakerEasySimulator.cpp
//  musicSequence_proto
//
//  Created by Ovis aries on 2014/10/02.
//
//

#include "lyricSpeakerEasySimulator.h"

void lyricSpeakerEasySimulator::setup(){
	sender.setup("localhost", 1556);
}

void lyricSpeakerEasySimulator::setMusic(string artist, string song){
	currentSong = song;
	currentArtist = artist;
}

void lyricSpeakerEasySimulator::play(){
	string command = "osascript -e 'tell application \"iTunes\" to play track \""+ currentSong +"\"'";
	cout << command << endl;
	system(command.c_str());

	ofxOscMessage m;
	m.setAddress("/lyric/play");
	m.addStringArg(currentSong);
	m.addStringArg(currentArtist);

	ofxOscMessage okM;
	okM.setAddress("/lyric/okSign");
	okM.addIntArg(1);

	sender.sendMessage(m);
	sender.sendMessage(okM);

}

void lyricSpeakerEasySimulator::stop(){
	string command = "osascript -e 'tell application \"iTunes\" to stop ";
	system(command.c_str());

	ofxOscMessage m;
	m.setAddress("/lyric/stop");
	m.addIntArg(1);
	sender.sendMessage(m);

}