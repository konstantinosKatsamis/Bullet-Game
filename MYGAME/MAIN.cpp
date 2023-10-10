#include "graphics.h"
#include "GAME.h"
#include "CONFIG.h"

void update(float ms)
{
    GAME* game = reinterpret_cast<GAME*>(graphics::getUserData());
    game->update();
}


void draw()
{
    GAME* game = reinterpret_cast<GAME*>(graphics::getUserData());
    game->draw();
}
 
int main()
{
    GAME mygame;

    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "MYGAME");

    graphics::setUserData(&mygame);

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);
 
    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    mygame.init();
    mygame.setDebugMode(false);

    graphics::startMessageLoop();
 
    return 0;
}