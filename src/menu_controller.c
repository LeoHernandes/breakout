#include "menu_controller.h"

void _render_menu_options(MenuOption selectedOption);
void _handle_user_input(MenuOption *selectedOption);

void main_menu()
{
    MenuOption menuOption = NEW_GAME;
    bool exitMainMenu = false;
    render_asset("assets/main_menu.txt", 0, 0);

    while (!exitMainMenu)
    {
        _render_menu_options(menuOption);
        present_frame();

        _handle_user_input(&menuOption);
    }
}

void _render_menu_options(MenuOption selectedOption)
{
    text("New Game", 4, 18, BLUE);
    text("Load Game", 4, 20, BLUE);
    text("Scores", 4, 22, BLUE);
    text("Quit", 4, 24, BLUE);

    switch (selectedOption)
    {
    case NEW_GAME:
        text_highlight("New Game", 4, 18, BLUE);
        break;
    case LOAD_GAME:
        text_highlight("Load Game", 4, 20, BLUE);
        break;
    case SCORES:
        text_highlight("Scores", 4, 22, BLUE);
        break;
    case QUIT:
        text_highlight("Quit", 4, 24, BLUE);
        break;
    }
}

void _handle_user_input(MenuOption *selectedOption)
{
    int key = getch();
    switch (key)
    {
    case KEY_UP:
        *selectedOption = (*selectedOption - 1 + 4) % 4;
        break;
    case KEY_DOWN:
        *selectedOption = (*selectedOption + 1) % 4;
        break;
    case '\n':
    case '\r':
    case KEY_ENTER:
        // Handle enter key
        break;
    default:
        break;
    }
}
