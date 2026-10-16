#include "game_controller.h"

void _update_scene(Game *game, float deltaTime)
{
    switch (game->gameState)
    {

    case PLAYING:
        // Update game playing logic
        break;
    case PAUSED:
        // Update paused logic
        break;
    case SAVING:
        // Update high scores logic
        break;
    case LOADING:
        // Handle exit logic
        break;
    default:
        break;
    }
}

void _render_scene(Game game)
{
    switch (game.gameState)
    {
    case PLAYING:
        // Render game playing scene
        break;
    case PAUSED:
        // Render paused scene
        break;
    case SAVING:
        // Render saving scene
        break;
    case LOADING:
        // Render loading scene
        break;
    default:
        break;
    }

    present_frame();
}

void game_loop()
{

    Game game = {
        .gameState = PLAYING};

    struct timespec previousTime,
        currentTime;
    float deltaTimeInSeconds = 0.0f;
    clock_gettime(CLOCK_MONOTONIC, &previousTime);

    while (true)
    {
        clock_gettime(CLOCK_MONOTONIC, &currentTime);
        deltaTimeInSeconds =
            (float)(currentTime.tv_sec - previousTime.tv_sec) +
            (currentTime.tv_nsec - previousTime.tv_nsec) / 1000000000.0f;
        previousTime = currentTime;

        _update_scene(&game, deltaTimeInSeconds);
        _render_scene(game);
    }
}
