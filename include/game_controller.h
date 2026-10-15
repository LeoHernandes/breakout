#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "entities.h"
#include "interface.h"
#include "time.h"
#include "stdbool.h"

typedef enum
{
    MAIN_MENU,
    DIFFICULTY,
    PLAYING,
    PAUSED,
    HIGH_SCORES,
    EXIT
} SceneType;

typedef struct
{
    SceneType sceneType;
    Player player;
    Ball ball;
    Paddle paddle;
    Brick bricks[MAX_BRICKS];
} Scene;

void game_loop();

#endif // GAME_CONTROLLER_H