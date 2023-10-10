#pragma once
#include "GAMEOBJECT.h"
#include "PLAYER.h"

class SFAIRA : public GAMEOBJECT, public SUGKROUSH
{
	float speed = 1.f;
	float thesiSfx;
	float thesiSfy;
	float size = 30;
	int fora;
	bool energo = false; // AN ZEI H SFAIRA ENERGO = TRUE AN OXI ENERGO = FALSE

public:
	void update() override;
	void draw() override;
	void init() override;
	
	float getThesiSfx() { return thesiSfx; }
	float getThesiSfy() { return thesiSfy; }
	
	int getForaSf() { return fora; }
	void setForaSf(int k) { fora = k; }
	
	void setThesiSfx(float x) { thesiSfx = x; }
	void setThesiSfy(float y) { thesiSfy = y; }

	bool getisActive() { return energo; }
	void setActive(bool b) { energo = b; }
	

	ORIO getSugkroush() const override;

	SFAIRA(const class GAME& mygame);
	~SFAIRA();
};