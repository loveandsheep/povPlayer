//
//  wordData.cpp
//  povPlayer
//
//  Created by Ovis aries on 2015/07/24.
//
//

#include "wordData.h"

bool wordData::update(float currentTime)
{
	if (currentTime > time && !finish)
	{
		finish = true;
		isViewing = true;
		return true;
	}
	
	return false;
}

void wordData::draw()
{
	if (isViewing)
	{
		ofRectangle bRect = fontPtr->getStringBoundingBox(word, 0, 0);
		
		ofPushMatrix();
		ofTranslate(pos);
		ofRotateZ(zRot);
		glScaled(scale, scale, scale);
		fontPtr->drawString(word, -bRect.width/2.0, bRect.height/2.0);
		ofPopMatrix();
	}
}

void wordData::disappear()
{
	isViewing = false;
}