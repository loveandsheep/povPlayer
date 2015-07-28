//
//  SongManager.h
//  povPlayer
//
//  Created by Ovis aries on 2015/07/24.
//
//

#ifndef __povPlayer__SongManager__
#define __povPlayer__SongManager__

#include "ofMain.h"
#include "SongData.h"

class SongManager{
public:
	void setup();
	void update();
	void draw();
	
	SongData testSong;
	vector< ofPtr<SongData> > songs;
};

#endif /* defined(__povPlayer__SongManager__) */
