#include "terminal.h"

void move_cursor_to(int x, int y)
{
    move(y - 1, x - 1);
}

void sleep(int milliseconds)
{
    napms(milliseconds);
}

void clear_screen()
{
    wclear(stdscr);
    wrefresh(stdscr);
}

int keyboard_hit()
{
    nodelay(stdscr, TRUE);
    int key = getch();
    nodelay(stdscr, FALSE);

    return key != ERR;
}

void print_char_at(int x, int y, chtype character)
{
    mvaddch(y - 1, x - 1, character);
}

void print_text_at(int x, int y, const char *text)
{
    mvaddstr(y - 1, x - 1, text);
}

void setup_terminal()
{
    initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

void text_color(int color)
{
    attron(COLOR_PAIR(color));
}