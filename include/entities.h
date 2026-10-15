#ifndef ENTITIES_H
#define ENTITIES_H

#include "stdbool.h"

#define PLAYER_NAME_MAX_LENGTH 4 // 3 + 1 counting null terminator
#define PADDLE_HEIGHT 2
#define MAX_BRICKS 100

typedef struct
{
    int x;
    int y;
} Vector2D;

typedef struct
{
    Vector2D position;
    Vector2D velocity;
} Ball;

typedef struct
{
    Vector2D topLeftCorner;
    unsigned int size;
    Vector2D velocity;
} Paddle;

typedef struct
{
    Vector2D topLeftCorner;
    unsigned short health;
    unsigned int points;
    unsigned int bonus;
} Brick;

typedef struct
{
    char name[PLAYER_NAME_MAX_LENGTH];
    unsigned int lifes;
    unsigned int points;
    bool pointsBuff;
    bool paddleBuff;
} Player;

#endif // ENTITIES_H