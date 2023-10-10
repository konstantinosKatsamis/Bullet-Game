#pragma once

#include <random>

float rand0to1();

bool checkTOIXOSx(float x, float y, float r);

bool checkTOIXOSy(float x, float y, float r);

bool checkSigrousiAntikimenwn(float xSf, float ySf, float rSf, float xP, float yP, float rP);

void drawText();

struct ORIO
{
	float cx, cy;
	float radius;
};