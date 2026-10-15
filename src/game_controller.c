#include "game_controller.h"

void _update_scene(Scene *scene, float deltaTime)
{
    switch (scene->sceneType)
    {
    case MAIN_MENU:
        // Update main menu logic
        break;
    case DIFFICULTY:
        // Update difficulty selection logic
        break;
    case PLAYING:
        // Update game playing logic
        break;
    case PAUSED:
        // Update paused logic
        break;
    case HIGH_SCORES:
        // Update high scores logic
        break;
    case EXIT:
        // Handle exit logic
        break;
    default:
        break;
    }
}

void _render_scene(Scene scene)
{
    switch (scene.sceneType)
    {
    case MAIN_MENU:
        render_main_menu();
        break;
    case DIFFICULTY:
        // Render difficulty selection
        break;
    case PLAYING:
        // Render game playing scene
        break;
    case PAUSED:
        // Render paused scene
        break;
    case HIGH_SCORES:
        // Render high scores scene
        break;
    case EXIT:
        // Handle exit
        break;
    default:
        break;
    }

    present_frame();
}

void game_loop()
{

    Scene scene = {
        .sceneType = MAIN_MENU};

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

        _update_scene(&scene, deltaTimeInSeconds);
        _render_scene(scene);
    }
}
