#include "util.h"
#include "CONFIG.h"
#include "graphics.h"

float rand0to1()
{
	return (rand() / (float)RAND_MAX)*400 + 250;
}

bool checkTOIXOSx(float x, float y, float r) // ELEGXEI SUGKROUSH TERATAKI-TOIXOS ME DE3IA/ARISTERA PLEURA RECTANGLE
{

	// APOSTASI GWNIWN DE3IA PLEURAS RECTANGLE APO TERATAKI
	float cde3ia = sqrt(((x - 147) * (x - 147)) + ((y - 92) * (y - 92))); // C PANW GWNIA RECTANGLE 
	float ade3ia = y - 92;// SIMEIO SUGKROUSHS TERATAKI - TOIXOS
	float caristera = sqrt(((x - 147) * (x - 147) + (y - 435) * (y - 435))); // ANTISTOIXA GIA KATW PLEURA
	float aaristera = y - 435;

	// IDIO ME PANW APLA GIA DE3IO TOIXO
	float zde3ia = sqrt(((x - 853) * (x - 853)) + ((y - 92) * (y - 92)));
	float wde3ia = y - 92;
	float zaristera = sqrt(((x - 853) * (x - 853) + (y - 435) * (y - 435)));
	float waristera = y - 435;


	if (sqrt((cde3ia * cde3ia) - (ade3ia * ade3ia)) < (r+25) && y > 92 && y < 436) {
		return true;
	}
	else if (sqrt((caristera * caristera) - (aaristera * aaristera)) < (r+25) && y > 92 && y < 436 && x < 122) {
		return true;
	}
	else if (sqrt((zaristera * zaristera) - (waristera * waristera)) < (r+25) && y > 92 && y < 436 && x>172 && x<828) {
		return true;
	}
	else if (sqrt((zde3ia * zde3ia) - (wde3ia * wde3ia)) < (r + 25) && y > 92 && y < 436 && x > 880) {
		return true;
	}
	else {
		return false;
	}

}

bool checkTOIXOSy(float x, float y, float r) // ELEGXEI SUGKROUSH TERATAKI TOIXOS ME PANW-KATW PLEURES
{
	// APOSTASI GWNIWN PANW PLEURAS RECTANGLE APO TERATAKI
	float cpanw = sqrt(((x - 147) * (x - 147)) + ((y - 92) * (y - 92))); // C PANW GWNIA RECTANGLE
	float apanw = x - 147; // SIMEIO SUGKROUSHS TERATAKI - TOIXOS
	float ckatw = sqrt(((x - 147) * (x - 147) + (y - 435) * (y - 435))); // ANTISTOIXA GIA KATW PLEURA
	float akatw = x- 147;

	// IDIO ME PANW APLA GIA DE3IO TOIXO
	float zpanw = sqrt(((x - 853) * (x - 853)) + ((y - 92) * (y - 92)));
	float wpanw = x - 853;
	float zkatw = sqrt(((x - 853) * (x - 853) + (y - 435) * (y - 435)));
	float wkatw = x - 853;


	if (sqrt((cpanw * cpanw) - (apanw * apanw)) < r && y < 92 && x > 121 && x < 173) {
		return true;
	}
	else if (sqrt((ckatw * ckatw) - (akatw * akatw)) < r && y > 436 && x > 121 && x < 173) {
		return true;
	}
	else if (sqrt((zpanw * zpanw) - (wpanw * wpanw)) < r && y < 92 && x > 827 && x < 881) {
		return true;
	}
	else if (sqrt((zkatw * zkatw) - (wkatw * wkatw)) < r && y > 436 && x > 827 && x < 881) {
		return true;
	}
	else {
		return false;
	}

}

bool checkSigrousiAntikimenwn(float xSf, float ySf, float rSf, float xP, float yP, float rP)
{//							x1           y1                   x2        y2
	// an apostash simiou apo simio einai tade return false
	// alios return true
	float apostash_simiwn = sqrt( (xP - xSf) * (xP - xSf) + (yP - ySf) * (yP - ySf));
	float apostash_aktinwn_mazi = rSf + rP;
	if (apostash_simiwn < apostash_aktinwn_mazi)
		return true;
	else
		return false;
}

void drawText()
{
	graphics::Brush br;
	br.texture = "";
	float saltos = CANVAS_HEIGHT * sinf(graphics::getGlobalTime() / 500.0f) / 40;
	char message[40];
	sprintf_s(message, " Press 'SPACE' to START ");
	graphics::drawText(280, 400 + saltos, 40, message, br);

	sprintf_s(message, " Press 'ESC' to EXIT ");
	graphics::drawText(410, 450 + saltos, 20, message, br);

	sprintf_s(message, "1ST    Player's   Buttons");
	graphics::drawText(40, 60, 35, message, br);
	sprintf_s(message, "UP - W");
	graphics::drawText(40, 110, 20, message, br);
	sprintf_s(message, "LEFT - A");
	graphics::drawText(40, 140, 20, message, br);
	sprintf_s(message, "RIGHT - D");
	graphics::drawText(40, 170, 20, message, br);
	sprintf_s(message, "DOWN - S");
	graphics::drawText(40, 200, 20, message, br);
	sprintf_s(message, "I - SHOOT UP");
	graphics::drawText(218, 110, 20, message, br);
	sprintf_s(message, "J - SHOOT LEFT");
	graphics::drawText(210, 140, 20, message, br);
	sprintf_s(message, "L - SHOOT RIGHT");
	graphics::drawText(210, 170, 20, message, br);
	sprintf_s(message, "K - SHOOT DOWN");
	graphics::drawText(210, 200, 20, message, br);

	sprintf_s(message, "2ND    Player's   Buttons");
	graphics::drawText(500, 60, 35, message, br);
	sprintf_s(message, "UP - ARROW UP");
	graphics::drawText(500, 110, 20, message, br);
	sprintf_s(message, "LEFT - ARROW LEFT");
	graphics::drawText(500, 140, 20, message, br);
	sprintf_s(message, "RIGHT - ARROW RIGHT");
	graphics::drawText(500, 170, 20, message, br);
	sprintf_s(message, "DOWN - ARROW DOWN");
	graphics::drawText(500, 200, 20, message, br);
	sprintf_s(message, "NUMPAD 8 - SHOOT UP");
	graphics::drawText(740, 110, 20, message, br);
	sprintf_s(message, "NUMPAD 4 - SHOOT LEFT");
	graphics::drawText(740, 140, 20, message, br);
	sprintf_s(message, "NUMPAD 6 - SHOOT RIGHT");
	graphics::drawText(740, 170, 20, message, br);
	sprintf_s(message, "NUMPAD 5 - SHOOT DOWN");
	graphics::drawText(740, 200, 20, message, br);

	sprintf_s(message, "Press  M  for  MINIGAME");
	graphics::drawText(750, 490, 20, message, br);

}


