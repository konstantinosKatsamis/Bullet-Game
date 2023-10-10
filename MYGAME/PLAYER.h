#pragma once
#include "GAMEOBJECT.h"
#include "CONFIG.h"

class PLAYER : public GAMEOBJECT, public SUGKROUSH
{
	float speed = 4.0f;
	float thesix = 100, thesiy = 100;
	float zwh = 1.0f;
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

	float getZwh()
	{ 
		return zwh;
	}
	void ipolipomenhZwh(float ipolipo)
	{ 
		zwh = std::max<float>(0.0f, zwh - ipolipo);
	}

	ORIO getSugkroush() const override;

	PLAYER(const class GAME& mygame);
	~PLAYER();
};