#pragma once

#include "GAMEOBJECT.h"
#include "graphics.h"
#include <random>


class TERATAKI : public GAMEOBJECT, public SUGKROUSH
{
	float posx = rand0to1()+100 , posy = rand0to1()-200;
	float speed = 0.1f;
	float size = 30;

	bool energo = true;// elegxos gia oria teratos mesa ston canva
	bool kinisix = false; // aristera
	bool kinisiy = false; 

public:

	float getposx() {
		return posx;
	}
	float getposy() {
		return posy;
	}
	void update() override;
	void draw() override;
	void init() override;
	bool isActive() { return energo; }
	void setActive(bool b)
	{
		energo = b;
	}

	TERATAKI(const class GAME& mygame);
	~TERATAKI();
	ORIO getSugkroush() const override;

	void changeDirx();
	void changeDiry();
};