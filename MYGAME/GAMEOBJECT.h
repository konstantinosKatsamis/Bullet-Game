#pragma once
#include "UTIL.h"

class SUGKROUSH
{
public:
	virtual ORIO getSugkroush() const = 0;
};

class GAMEOBJECT
{
public:
	const class GAME& game;
public:
	GAMEOBJECT(const class GAME& mygame);
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void init() = 0;
};
