#pragma once
#include "GAMEOBJECT.h"
#include "CONFIG.h"

class PLAYER2 : public GAMEOBJECT, public SUGKROUSH
{
	float speed = 4.0f;
	float thesix = 900, thesiy = 100;
	float zwh2 = 1.0f;
public:
	void update() override;
	void draw() override;
	void init() override;
	float getTHESIX() 
	{ 
		return thesix; 
	}
	float getTHESIY() 
	{ 
		return thesiy; 
	}

	void setTHESIX(float x);
	void setTHESIY(float y);

	float getZwh2() 
	{ 
		return zwh2; 
	}
	void ipolipomenhZwh2(float ipolipo) 
	{ 
		zwh2 = std::max<float>(0.0f, zwh2 - ipolipo);
	}

	ORIO getSugkroush() const override;

	PLAYER2(const class GAME& mygame);
	~PLAYER2();

};