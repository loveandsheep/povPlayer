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

class lyricUnit;

class SongData{
public:
	
	
	
};


class lyricUnit{
	lyricUnit()
	{
		word.clear();
		durs.clear();
		headTime = 0.0;
	}
	
	void setLyric(float _headTime)
	{
		headTime = _headTime;
	}
	
	void addWord(float duration, string wrd)
	{
		durs.push_back(duration);
		word.push_back(string(wrd));
	}
	
	float getTotalDuration()
	{
		float ret = 0.0;
		for (int i = 0;i < durs.size();i++)
			ret += durs[i];
		return ret;
	}
	
protected:
	
	float headTime;//歌詞の開始時刻
	
	vector<float>	durs;//ワードの尺
	vector<string>	word;//文節化した歌詞の配列
};



#endif /* defined(__povPlayer__SongData__) */
