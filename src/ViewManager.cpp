//
//  ViewManager.cpp
//  povPlayer
//
//  Created by Ovis aries on 2015/07/17.
//
//

#include "ViewManager.h"

void viewManager::setup(int w, int h)
{
	ofFbo::Settings setting;
	setting.internalformat = GL_RGB;
	setting.width = w;
	setting.height = h;
	
	buffer.allocate(setting);
	testRec.allocate(w, h, OF_IMAGE_COLOR);
}

void viewManager::update()
{
	
}

void viewManager::draw()
{

}

void viewManager::drawBuf()
{
	buffer.draw(0,0);
}

void viewManager::sendBuffer()
{
	ofPixels pix;
	pix.allocate(buffer.getWidth(), buffer.getHeight(), 3);
	
	buffer.readToPixels(pix);
	unsigned char* raw = pix.getPixels();
	int numPix = pix.getWidth() * pix.getHeight();
	
	vector<unsigned char> sendBytes;
	sendBytes.clear();
	
	for (int i = 0;i < 3;i++)
	{
		int pxCnt = 0;
		int duplicated = 0;
		unsigned char current = raw[i];
	
		while (pxCnt < numPix) {
			
			if (raw[pxCnt * 3 + i] == current)
			{
				duplicated++;
				if (duplicated == 0xFF)
				{
					sendBytes.push_back(current);
					sendBytes.push_back(duplicated);
					duplicated = 0;
				}
			}else{
				sendBytes.push_back(current);
				sendBytes.push_back(duplicated);
				current = raw[pxCnt * 3 + i];
				duplicated = 1;
			}
			
			pxCnt++;
		}
		
		sendBytes.push_back(current);
		sendBytes.push_back(duplicated-1);
		sendBytes.push_back(0x0);
		sendBytes.push_back(0x0);//0x0が2回続いたら終端処理
	}
	
	
	sendBytes.push_back(0x0);
	sendBytes.push_back(0x0);
	sendBytes.push_back(0x0);
	sendBytes.push_back(0x0);//0x0が4回続いたら初期状態リクエスト
	
//	serial.writeBytes(&sendBytes[0],sendBytes.size());
	test_receive(&sendBytes[0], sendBytes.size());
}


void viewManager::test_receive(unsigned char *buf, int num)
{
#define PHASE_IDLE 0
#define PHASE_RED 1
#define PHASE_BLUE 2
#define PHASE_GREEN 3
#define SUBPH_COL 0
#define SUBPH_RUNL 1
#define PIX_W 64
#define PIX_H 64
#define NUMPIX PIX_W * PIX_H * 3
	
	int phase = PHASE_IDLE;
	int subPhase = SUBPH_COL;
	int curIndex = 0;
	int zeroCounter = 0;
	bool nextColorFlg = false;
	unsigned char colorStock;
	unsigned char pixels[NUMPIX];
	
	for (int i = 0;i < num;i++)
	{
		
		unsigned char rec = buf[i];//受信したデータ
		if (phase == PHASE_IDLE)
		{
			phase = PHASE_RED;
		}
		
		if (phase != PHASE_IDLE)
		{
			if (nextColorFlg && (rec != 0x0)){
				phase++;//0x0 2連続で次の色
				nextColorFlg = false;
				curIndex = 0;
			}
			
			if (subPhase == SUBPH_COL)//色情報の取得
			{
				colorStock = rec;
				subPhase = SUBPH_RUNL;
			}
			else if (subPhase == SUBPH_RUNL)//連続情報の取得・格納
			{
				subPhase = SUBPH_COL;
				for (int j = 0;j < rec;j++)
				{
					int idx = MIN(NUMPIX - 1, curIndex + j * 3 + phase - 1);
					pixels[idx] = colorStock;
				}
				
				curIndex += rec * 3;
			}
		}
		
		if (rec == 0x0)
		{
			zeroCounter++;
			if (zeroCounter == 2){
				nextColorFlg = true;
			}
			if (zeroCounter == 4)
			{
				if (phase == PHASE_GREEN)
				{
					testRec.setFromPixels(pixels, PIX_W, PIX_H, OF_IMAGE_COLOR);
					testRec.update();
				}
				
				phase = PHASE_IDLE;
				subPhase = SUBPH_COL;
				zeroCounter = 0;
				curIndex = 0;
				nextColorFlg = false;
			}
		}else{
			nextColorFlg = false;
			zeroCounter = 0;
		}
	}
}

