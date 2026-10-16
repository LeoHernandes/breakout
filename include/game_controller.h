#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "entities.h"
#include "interface.h"
#include "time.h"
#include "stdbool.h"

typedef enum
{
    PLAYING,
    PAUSED,
    SAVING,
    LOADING,
} GameState;

typedef struct
{
    GameState gameState;
    Player player;
    Ball ball;
    Paddle paddle;
    Brick bricks[MAX_BRICKS];
} Game;

void game_loop();

#endif // GAME_CONTROLLER_H