#include "PLAYER2.h"
#include "graphics.h"
#include "GAME.h"



void PLAYER2::update()
{
	// PLIKTRA GIA KINHSH PAIKTH
	if (graphics::getKeyState(graphics::SCANCODE_LEFT))
	{
		thesix -= speed * graphics::getDeltaTime() / 30.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_RIGHT))
	{
		thesix += speed * graphics::getDeltaTime() / 30.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_UP))
	{
		thesiy -= speed * graphics::getDeltaTime() / 30.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_DOWN))
	{
		thesiy += speed * graphics::getDeltaTime() / 30.0f;
	}

	// ORIA PAIKTH MESA STON KOUTI
	if (thesix < 15 ) thesix =  15;
	if (thesix > CANVAS_WIDTH - 15) thesix = CANVAS_WIDTH- 15;
	if (thesiy < 15) thesiy = 15;
	if (thesiy > CANVAS_HEIGHT - 15) thesiy = CANVAS_HEIGHT - 15;

}


void PLAYER2::draw()
{
	graphics::Brush br;
	graphics::Brush br2;

	// SECTOR GIA THN OURA TOU PACMAN
	graphics::setOrientation(+180.f);
	br2.outline_opacity = 0.0f;
	br2.fill_color[0] = 1.0f; // XRWMA OURAS
	br2.fill_color[1] = 1.0f;
	br2.fill_color[2] = 0.0f;
	br2.fill_secondary_color[0] = 1.0f; // 2o XRWMA OURAS
	br2.fill_secondary_color[1] = 0.5f;
	br2.fill_secondary_color[2] = 1.0f;
	br2.fill_opacity = 3.0f;
	br2.fill_secondary_opacity = 0.0f;
	br2.gradient = true;
	br2.gradient_dir_u = 0.8f;
	br2.gradient_dir_v = 1.f;
	graphics::drawSector(thesix + 24, thesiy + 10, 15, 32, 0, 90, br2);
	graphics::setOrientation(0.f);

	// paikths eikona
	br.outline_opacity = 0.0f;
	br.texture = std::string(ASSET_PATH) + "PAIKTHS_DE3IA.png";
	graphics::drawRect(thesix, thesiy, 30, 30, br);

	if (game.getDebugMode())
	{
		graphics::Brush br;
		br.outline_opacity = 1.0f;
		br.texture = "";
		br.fill_color[0] = 0.0f;
		br.fill_color[1] = 0.3f;
		br.fill_color[2] = 0.3f;
		br.fill_opacity = 0.3f;
		br.gradient = 0;
		ORIO hull = getSugkroush();
		graphics::drawDisk(hull.cx, hull.cy, hull.radius, br);
	}

}

void PLAYER2::init()
{
}

void PLAYER2::setTHESIX(float x)
{

	if (thesix > 107 && thesix < 187)
	{
		if (thesix - 107 < 10)
		{
			thesix = 107;
		}
		else {
			thesix = 187;
		}
	}
	if (thesix > 814 && thesix < 894)
	{
		if (thesix - 814 < 10)
		{
			thesix = 814;
		}
		else {
			thesix = 894;
		}
	}

}

void PLAYER2::setTHESIY(float y)
{

	if (thesix > 107 && thesix < 187)
	{
		if (thesiy - 77 < 20)
		{
			thesiy = 77;
		}
		else
		{
			thesiy = 450;
		}
	}
	if (thesix > 814 && thesix < 894) {
		if (thesiy - 77 < 20) {
			thesiy = 77;
		}
		else {
			thesiy = 450;
		}
	}

}

ORIO PLAYER2::getSugkroush() const
{
	ORIO orio;
	orio.cx = thesix;
	orio.cy = thesiy;
	orio.radius = 30 * 0.50f;
	return orio;
}

PLAYER2::PLAYER2(const GAME& mygame)
	: GAMEOBJECT(mygame)
{
	init();
}

PLAYER2::~PLAYER2()
{
}
