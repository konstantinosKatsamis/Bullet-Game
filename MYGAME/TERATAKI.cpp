#include "TERATAKI.h"
#include "CONFIG.h"
#include <random>
#include "UTIL.h"
#include "GAME.h"

void TERATAKI::update()
{
	if (!kinisix) {
		posx -= speed * graphics::getDeltaTime();
	}
	else {
		posx += speed * graphics::getDeltaTime();
	}

	if (!kinisiy) {
		posy -= speed * graphics::getDeltaTime();
	}
	else {
		posy += speed * graphics::getDeltaTime();
	}

	if(posx <= 15) {
		changeDirx();
	}
	else if(posx >= CANVAS_WIDTH - 15) {
		changeDirx();
	}

	if (posy <= 15) {
		changeDiry();
	}
	else if (posy >= CANVAS_HEIGHT - 15){
		changeDiry();
	}

	if (posx < -size)
		energo = false;

}

void TERATAKI::draw()
{
	graphics::Brush vourtsa;
	vourtsa.outline_opacity = 0.0f;
	vourtsa.texture = std::string(ASSET_PATH) + "TERATAKI.png";
	graphics::drawRect(posx, posy, size+10, size, vourtsa);

	if (game.getDebugMode())
	{
		graphics::Brush br;
		br.outline_opacity = 1.0f;
		br.texture = "";
		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 0.3f;
		br.fill_color[2] = 0.3f;
		br.fill_opacity = 0.3f;
		br.gradient = false;
		ORIO hull = getSugkroush();
		graphics::drawDisk(hull.cx, hull.cy, hull.radius, br);
	}
}

void TERATAKI::init()
{
}


TERATAKI::TERATAKI(const class GAME& mygame)
	:GAMEOBJECT(mygame)
{
	init();
}

TERATAKI::~TERATAKI()
{
	
}

ORIO TERATAKI::getSugkroush() const
{
	ORIO orio;
	orio.cx = posx;
	orio.cy = posy;
	orio.radius = size * 0.45f;
	return orio;
}

void TERATAKI::changeDirx()
{

	if (kinisix) {
		kinisix = false;
	}
	else {
		kinisix = true;
	}

}

void TERATAKI::changeDiry()
{

	if (kinisiy) {
		kinisiy = false;
	}
	else {
		kinisiy = true;
	}

}