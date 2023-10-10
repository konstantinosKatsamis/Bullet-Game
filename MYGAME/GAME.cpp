#include "GAME.h"
#include "graphics.h"
#include "CONFIG.h"
#include "UTIL.h"

void GAME::spawnteras()
{
	teras = new TERATAKI(*this);
	agelh.add(teras);
}


void GAME::spawnSfaira1()
{
	sfaira1 = new SFAIRA(*this);
	sfaira1->setActive(true);	
}

void GAME::spawnSfaira2()
{
	sfaira2 = new SFAIRA(*this);
	sfaira2->setActive(true);
}

void GAME::checkSfaira()
{
	if (sfaira1 && !sfaira1->getisActive())
	{
		delete sfaira1;
		sfaira1 = nullptr;
		setPURAULOS1(false);
	}
	if (sfaira2 && !sfaira2->getisActive())
	{
		delete sfaira2;
		sfaira2 = nullptr;
		setPURAULOS2(false);
	}
}

void GAME::update()
{
	if (test_space == 0) {
		if (graphics::getKeyState(graphics::SCANCODE_SPACE)) // EKKINHSH TOU PAIXNIDIOU , ALLAGH OTHONIS
		{
			setSpace(1);
			setCounter(1);
		}
		if (graphics::getKeyState(graphics::SCANCODE_M)) // EKKINHSH TOU MINIGAME , ALLAGH OTHONIS
		{
			setSpace(3);
			setCounter(0);
		}
	}

	if (test_space == 1) {
		if (!uparxw)
		{
			paikths = new PLAYER(*this);
			uparxw = true;
		}
		if (paikths) {
			paikths->update();
			ORIO p1 = paikths->getSugkroush();

			if (checkTOIXOSx(p1.cx, p1.cy, p1.radius)) {
				paikths->setTHESIX(p1.cx);
			}
			if (checkTOIXOSy(p1.cx, p1.cy, p1.radius)) {
				paikths->setTHESIY(p1.cy);
			}
		}

		if (!uparxw2)
		{
			paikths2 = new PLAYER2(*this);
			uparxw2 = true;
		}
		if (paikths2) {
			paikths2->update();
			ORIO p2 = paikths2->getSugkroush();

			if (checkTOIXOSx(p2.cx, p2.cy, p2.radius)) {
				paikths2->setTHESIX(p2.cx);
			}
			if (checkTOIXOSy(p2.cx, p2.cy, p2.radius)) {
				paikths2->setTHESIY(p2.cy);
			}
		}
		if (agelh.isEmpty()) {
			spawnteras();
		}
		agelh[0]->update();
		if (graphics::getGlobalTime() > 15000) {
			if (agelh.count() == 1) {
				spawnteras();
			}
			agelh[1]->update();
		}
		if (graphics::getGlobalTime() > 20000) {
			if (agelh.count() == 2) {
				spawnteras();
			}
			agelh[2]->update();
		}
		for (int i = 0; i < agelh.count(); i++) {
			ORIO o1 = agelh[i]->getSugkroush();
			if (checkTOIXOSx(o1.cx, o1.cy, o1.radius)) {
				agelh[i]->changeDirx();
			}
			if (checkTOIXOSy(o1.cx, o1.cy, o1.radius)) {
				agelh[i]->changeDiry();
			}
		}

		checkSfaira();
		// KOUMPIA GIA SHOOT PAIKTH 1
		if (graphics::getKeyState(graphics::SCANCODE_J) && !PURAULOS1) {
			spawnSfaira1();
			graphics::playSound(std::string(ASSET_PATH) + "PEWPEW.mp3", 0.2f, false);
			sfaira1->setForaSf(1);
			sfaira1->setThesiSfx(paikths->getTHESIX() - 16);
			sfaira1->setThesiSfy(paikths->getTHESIY() + 5);
			setPURAULOS1(true);
		}
		else if (graphics::getKeyState(graphics::SCANCODE_L) && !PURAULOS1) {
			spawnSfaira1();
			graphics::playSound(std::string(ASSET_PATH) + "PEWPEW.mp3", 0.2f, false);
			sfaira1->setForaSf(2);
			sfaira1->setThesiSfx(paikths->getTHESIX() + 16);
			sfaira1->setThesiSfy(paikths->getTHESIY() + 5);
			setPURAULOS1(true);
		}
		else if (graphics::getKeyState(graphics::SCANCODE_I) && !PURAULOS1) {
			spawnSfaira1();
			graphics::playSound(std::string(ASSET_PATH) + "PEWPEW.mp3", 0.2f, false);
			sfaira1->setForaSf(3);
			sfaira1->setThesiSfx(paikths->getTHESIX());
			sfaira1->setThesiSfy(paikths->getTHESIY() - 6);
			setPURAULOS1(true);
		}
		else if (graphics::getKeyState(graphics::SCANCODE_K) && !PURAULOS1) {
			spawnSfaira1();
			graphics::playSound(std::string(ASSET_PATH) + "PEWPEW.mp3", 0.2f, false);
			sfaira1->setForaSf(4);
			sfaira1->setThesiSfx(paikths->getTHESIX());
			sfaira1->setThesiSfy(paikths->getTHESIY() + 16);
			setPURAULOS1(true);
		}

		// KOUMPIA GIA SHOOT PAIKTH 2
		if (graphics::getKeyState(graphics::SCANCODE_KP_4) && !PURAULOS2) {
			spawnSfaira2();
			graphics::playSound(std::string(ASSET_PATH) + "PEWPEW.mp3", 0.2f, false);
			sfaira2->setForaSf(1);
			sfaira2->setThesiSfx(paikths2->getTHESIX() - 16);
			sfaira2->setThesiSfy(paikths2->getTHESIY() + 5);
			setPURAULOS2(true);
		}
		else if (graphics::getKeyState(graphics::SCANCODE_KP_6) && !PURAULOS2) {
			spawnSfaira2();
			graphics::playSound(std::string(ASSET_PATH) + "PEWPEW.mp3", 0.2f, false);
			sfaira2->setForaSf(2);
			sfaira2->setThesiSfx(paikths2->getTHESIX() + 16);
			sfaira2->setThesiSfy(paikths2->getTHESIY() + 5);
			setPURAULOS2(true);
		}
		else if (graphics::getKeyState(graphics::SCANCODE_KP_8) && !PURAULOS2) {
			spawnSfaira2();
			graphics::playSound(std::string(ASSET_PATH) + "PEWPEW.mp3", 0.2f, false);
			sfaira2->setForaSf(3);
			sfaira2->setThesiSfx(paikths2->getTHESIX());
			sfaira2->setThesiSfy(paikths2->getTHESIY() - 6);
			setPURAULOS2(true);
		}
		else if (graphics::getKeyState(graphics::SCANCODE_KP_5) && !PURAULOS2) {
			spawnSfaira2();
			graphics::playSound(std::string(ASSET_PATH) + "PEWPEW.mp3", 0.2f, false);
			sfaira2->setForaSf(4);
			sfaira2->setThesiSfx(paikths2->getTHESIX());
			sfaira2->setThesiSfy(paikths2->getTHESIY() + 16);
			setPURAULOS2(true);
		}

		if (sfaira1) {
			sfaira1->update();
			ORIO s1 = sfaira1->getSugkroush();
			ORIO orioPaikth2 = paikths2->getSugkroush();
			if (checkTOIXOSx(s1.cx, s1.cy, s1.radius)) {
				sfaira1->setActive(false);
				setPURAULOS1(false);
			}
			if (checkTOIXOSy(s1.cx, s1.cy, s1.radius)) {
				sfaira1->setActive(false);
				setPURAULOS1(false);
			}
			if (checkSigrousiAntikimenwn(s1.cx, s1.cy, s1.radius, orioPaikth2.cx, orioPaikth2.cy, orioPaikth2.radius))
			{
				sfaira1->setActive(false);
				setPURAULOS1(false);
				paikths2->ipolipomenhZwh2(0.1f);
			}
			for (int i = 0; i < agelh.count(); i++) {
				ORIO t1 = agelh[i]->getSugkroush();
				if (checkSigrousiAntikimenwn(s1.cx, s1.cy, s1.radius, t1.cx, t1.cy, t1.radius))
				{
					sfaira1->setActive(false);
					setPURAULOS1(false);
				}
			}
		}

		if (sfaira2) {
			sfaira2->update();
			ORIO s2 = sfaira2->getSugkroush();
			ORIO orioPaikth = paikths->getSugkroush();
			if (checkTOIXOSx(s2.cx, s2.cy, s2.radius)) {
				sfaira2->setActive(false);
				setPURAULOS2(false);
			}
			if (checkTOIXOSy(s2.cx, s2.cy, s2.radius)) {
				sfaira2->setActive(false);
				setPURAULOS2(false);
			}
			if (checkSigrousiAntikimenwn(s2.cx, s2.cy, s2.radius, orioPaikth.cx, orioPaikth.cy, orioPaikth.radius))
			{
				sfaira2->setActive(false);
				setPURAULOS2(false);
				paikths->ipolipomenhZwh(0.1f);
			}
			for (int i = 0; i < agelh.count(); i++) {
				ORIO t2 = agelh[i]->getSugkroush();
				if (checkSigrousiAntikimenwn(s2.cx, s2.cy, s2.radius, t2.cx, t2.cy, t2.radius))
				{
					sfaira2->setActive(false);
					setPURAULOS2(false);
				}
			}
		}

		//elegxos gia siggrousi teratos k paikth
		if (paikths && !agelh.isEmpty() && paikths2) {
			ORIO orioPaikth = paikths->getSugkroush();
			ORIO orioPaikth2 = paikths2->getSugkroush();
			for (int i = 0; i < agelh.count(); i++) {
				ORIO t = agelh[i]->getSugkroush();
				if (checkSigrousiAntikimenwn(t.cx, t.cy, t.radius, orioPaikth.cx, orioPaikth.cy, orioPaikth.radius)) {
					paikths->ipolipomenhZwh(0.005f);
				}
				if (checkSigrousiAntikimenwn(t.cx, t.cy, t.radius, orioPaikth2.cx, orioPaikth2.cy, orioPaikth2.radius)) {
					paikths2->ipolipomenhZwh2(0.005f);
				}
			}
		}


		if (paikths && paikths->getZwh() <= 0.0f) {
			setSpace(2);
			setCounter(2);
		}
		if (paikths2 && paikths2->getZwh2() <= 0.0f) {
			setSpace(2);
			setCounter(2);
		}
	}

	if (test_space == 2) {
		if (graphics::getKeyState(graphics::SCANCODE_R)) // EPANEKKINHSH TOU PAIXNIDIOU , ALLAGH OTHONIS
		{
			setSpace(0);
			setCounter(0);
			GAME::init();
			GAME::~GAME();
		}
	}

	if (test_space == 3) {
		if (graphics::getKeyState(graphics::SCANCODE_R)) // EPANEKKINHSH TOU PAIXNIDIOU , ALLAGH OTHONIS
		{
			setSpace(0);
			setCounter(0);
		}
	}
}

void GAME::draw()
{
	if (test_space == 0)
	{
		graphics::Brush br;
		br.texture = std::string(ASSET_PATH) + "TOPIO_ARXIKI.png";
		br.outline_opacity = 0.0f;
		graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

		drawText();

	}
	else if (test_space == 1)
	{
		graphics::Brush br;
		graphics::Brush br2;
		br.texture = std::string(ASSET_PATH) + "TOPIO_MAXHS.png";
		br.outline_opacity = 0.0f;
		graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

		if (paikths2)
			paikths2->draw();
		if (paikths)
			paikths->draw();
		if (!agelh.isEmpty()) {
			agelh[0]->draw();
			if (graphics::getGlobalTime() > 15000) {
				agelh[1]->draw();
			}
			if (graphics::getGlobalTime() > 20000) {
				agelh[2]->draw();
			}
		}
		if (sfaira1) {
			sfaira1->draw();
		}
		if (sfaira2) {
			sfaira2->draw();
		}

		br2.texture = std::string(ASSET_PATH) + "TOIXAKI.png";
		br2.outline_opacity = 0.0f;
		graphics::drawRect(854, 263, 53, 343, br2);

		graphics::setOrientation(0.f);
		br2.texture = std::string(ASSET_PATH) + "TOIXAKI.png";
		br2.outline_opacity = 0.0f;
		graphics::drawRect(147, 263, 53, 343, br2);
		graphics::setOrientation(0.f);

		if (counter == 1)
		{
			setCounter(0);
			GAME::init();
		}

		if (paikths && paikths2 && debug)
		{
			graphics::Brush br3;
			char message[40];
			sprintf_s(message, "(%6.2f, %6.2f)", paikths->getTHESIX(), paikths->getTHESIY());
			graphics::drawText(10, 70, 20, message, br3);

			sprintf_s(message, "(%6.2f, %6.2f)", paikths2->getTHESIX(), paikths2->getTHESIY());
			graphics::drawText(830, 70, 20, message, br3);

			graphics::Brush bri;
			bri.outline_opacity = 1.0f;
			bri.fill_color[0] = 0.0f;
			bri.fill_color[1] = 0.3f;
			bri.fill_color[2] = 0.3f;
			bri.fill_opacity = 0.3f;
			bri.gradient = 0;
			graphics::drawRect(147, 263.5, 51, 342, bri);
			graphics::drawRect(854, 264, 51, 342, bri);
		}
		if (paikths && paikths2) {
			//zwh gia paikth
			float paikths_life = paikths ? paikths->getZwh() : 0.0f;

			graphics::Brush lBr;
			lBr.outline_opacity = 0.0f;
			lBr.fill_color[0] = 1.0f;
			lBr.fill_color[1] = 0.2f;
			lBr.fill_color[2] = 0.2f;
			lBr.texture = "";
			lBr.fill_secondary_color[0] = 0.2f;
			lBr.fill_secondary_color[1] = 0.2f;
			lBr.fill_secondary_color[2] = 1.0f;
			lBr.gradient = true;
			lBr.gradient_dir_u = 1.0f;
			lBr.gradient_dir_v = 0.0f;
			graphics::drawRect(100 - ((1.0f - paikths_life) * 120 / 2), 30, paikths_life * 120, 20, lBr);
			lBr.outline_opacity = 1.0f;
			lBr.gradient = false;
			lBr.fill_opacity = 0.0f;
			graphics::drawRect(100, 30, 121, 21, lBr);

			//zwh gia paikth2
			float paikths_life2 = paikths2 ? paikths2->getZwh2() : 0.0f;
			graphics::Brush lBr2;
			lBr2.outline_opacity = 0.0f;
			lBr2.fill_color[0] = 1.0f;
			lBr2.fill_color[1] = 0.2f;
			lBr2.fill_color[2] = 0.2f;
			lBr2.texture = "";
			lBr2.fill_secondary_color[0] = 0.2f;
			lBr2.fill_secondary_color[1] = 0.2f;
			lBr2.fill_secondary_color[2] = 1.0f;
			lBr2.gradient = true;
			lBr2.gradient_dir_u = 1.0f;
			lBr2.gradient_dir_v = 0.0f;
			graphics::drawRect(CANVAS_WIDTH - 100 - ((1.0f - paikths_life2) * 120 / 2), 30, paikths_life2 * 120, 20, lBr2);

			lBr2.outline_opacity = 1.0f;
			lBr2.gradient = false;
			lBr2.fill_opacity = 0.0f;
			graphics::drawRect(CANVAS_WIDTH - 100, 30, 120, 20, lBr2);
		}
	}
	else if (test_space == 2) {
		graphics::Brush br;
		br.texture = std::string(ASSET_PATH) + "TOPIO_TELIKO.png";
		br.outline_opacity = 0.0f;
		graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

		if (paikths->getZwh() > paikths2->getZwh2()) {
			graphics::Brush br;
			br.texture = "";
			char message[40];
			sprintf_s(message, "PLAYER 1 WON THE GAME");
			graphics::drawText(120, 130, 60, message, br);
		}
		else if (paikths->getZwh() < paikths2->getZwh2()) {
			graphics::Brush br;
			br.texture = "";
			char message[40];
			sprintf_s(message, "PLAYER 2 WON THE GAME");
			graphics::drawText(120, 130, 60, message, br);
		}
		br.texture = "";
		char message1[40];
		sprintf_s(message1, "Press  ESC  to  exit  the  GAME");
		graphics::drawText(700, 490, 20, message1, br);

		br.texture = "";
		char message2[40];
		sprintf_s(message2, "Press  R  to  return  to  MAIN  MENU");
		graphics::drawText(335, 250, 20, message2, br);

		if (counter == 2)
		{
			setCounter(0);
			GAME::init();
		}
	}
	else if (test_space == 3) {
		graphics::Brush br;
		br.texture = std::string(ASSET_PATH) + "CHICKEN.png";
		br.outline_opacity = 0.0f;
		graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

		br.texture = "";
		char message2[40];
		sprintf_s(message2, "Press  R  to  return  to  MAIN  MENU");
		graphics::drawText(335, 380, 20, message2, br);
	}
}

void GAME::init()
{
	if (test_space == 0)
	{
		graphics::setFont(std::string(ASSET_PATH) + "NASALIZATION.TTF");
		graphics::stopMusic(0);
		graphics::playMusic(std::string(ASSET_PATH) + "ARXIKI.mp3", 0.5f, true, 3000);
	}
	else if (test_space == 1)
	{
		graphics::stopMusic(0);
		graphics::playMusic(std::string(ASSET_PATH) + "MAXH.mp3", 0.5f, true, 1000);
	}
	else if(test_space == 2){
		graphics::stopMusic(0);
		graphics::playMusic(std::string(ASSET_PATH) + "ARXIKI.mp3", 0.5f, true, 1000);
	}

}

GAME::GAME()
{	
}

GAME::~GAME()
{
	if (paikths && paikths2)
	{
		delete paikths;
		delete paikths2;
		paikths = nullptr;
		paikths2 = nullptr;
		uparxw = false;
		uparxw2 = false;
	}

	if (sfaira1 && sfaira2) {
		delete sfaira1;
		delete sfaira2;
		sfaira1 = nullptr;
		sfaira2 = nullptr;
		PURAULOS1 = false;
		PURAULOS2 = false;
	}

	if (!agelh.isEmpty()) {
		agelh.clear();
		delete teras;
		teras = nullptr;
	}
}
