#include "SFAIRA.h"
#include "graphics.h"
#include "CONFIG.h"
#include "GAME.h"

void SFAIRA::update()
{

	if (fora == 1) {
		thesiSfx -= speed * graphics::getDeltaTime();
	} // J
	else if (fora == 2){ 
		thesiSfx += speed * graphics::getDeltaTime(); 
	} // L
	else if (fora == 3){ 
		thesiSfy -= speed * graphics::getDeltaTime(); 
	} // I
	else if (fora == 4){ 
		thesiSfy += speed * graphics::getDeltaTime();
	} // K

	if (thesiSfx < -size || thesiSfx > 1000+size || thesiSfy<-size || thesiSfy > 500+size)
		energo = false;

}

void SFAIRA::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = std::string(ASSET_PATH) + "SFAIRA.png";
	graphics::drawRect(thesiSfx, thesiSfy, 35, 35, br);

	if (game.getDebugMode())
	{
		graphics::Brush br2;
		br2.outline_opacity = 1.0f;
		br2.texture = "";
		br2.fill_color[0] = 1.0f;
		br2.fill_color[1] = 0.3f;
		br2.fill_color[2] = 0.3f;
		br2.fill_opacity = 0.3f;
		br2.gradient = false;
		ORIO hull2 = getSugkroush();
		graphics::drawDisk(hull2.cx, hull2.cy, hull2.radius, br2);
	}
}

void SFAIRA::init()
{
}
SFAIRA::SFAIRA(const class GAME& mygame)
	: GAMEOBJECT(mygame)
{
    init();
}

SFAIRA::~SFAIRA()
{
}

ORIO SFAIRA::getSugkroush() const
{
	ORIO orio;
	orio.cx = thesiSfx;
	orio.cy = thesiSfy-8;
	orio.radius = 17 * 0.45f;
	return orio;
}
