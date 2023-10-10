#pragma once

#include "PLAYER.h"
#include "PLAYER2.h"
#include "TERATAKI.h"
#include "SFAIRA.h"
#include "MYCOLLECTION.h"
using namespace std;


class GAME
{
	bool debug = false;
		
		PLAYER* paikths = nullptr;
		PLAYER2* paikths2 = nullptr;
		bool uparxw = false;			// parameters gia tous paiktes
		bool uparxw2 = false;

		int test_space = 0;				// parameter gia thn othoni
		int counter = 0;				// parameter gia thn mousiki

		TERATAKI* teras = nullptr;

		MYCOLLECTION<TERATAKI> agelh;

		void spawnteras();

		SFAIRA* sfaira1 = nullptr;
		SFAIRA* sfaira2 = nullptr;
		bool PURAULOS1 = false;
		bool PURAULOS2 = false;

		void spawnSfaira1();
		void spawnSfaira2();
		void checkSfaira();

		bool getPURAULOS1() { return PURAULOS1; }
		void setPURAULOS1(bool b) { PURAULOS1 = b; }
		bool getPURAULOS2() { return PURAULOS2; }
		void setPURAULOS2(bool b) { PURAULOS2 = b; }



public:

	void setDebugMode(bool d) { debug = d; }
	bool getDebugMode() const { return debug; }

	void setSpace(int b) 
	{
		test_space = b;
	}
	int getSpace()
	{
		return test_space;
	}

	void setCounter(int x)
	{
		counter = x;
	}
	int getCounter()
	{
		return counter;
	}

	void update();
	void draw();
	void init();
	GAME();
	~GAME();
};
