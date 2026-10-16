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
    mvaddch(y, x, character);
}

void print_text_at(int x, int y, const char *text)
{
    mvaddstr(y, x, text);
}

void initialize_terminal()
{
    initscr();
    keypad(stdscr, TRUE); // enable special keys (like arrow keys)
    noecho();             // disable echoing of typed characters
    curs_set(0);          // invisible cursor

    int foregroundColors[] = {
        COLOR_BLACK,
        COLOR_WHITE,
        COLOR_RED,
        COLOR_GREEN,
        COLOR_YELLOW,
        COLOR_BLUE,
        COLOR_MAGENTA,
        COLOR_CYAN,
    };
    int backgroundColors[] = {
        COLOR_BLACK,
        COLOR_WHITE};
    start_color();

    for (int bgIndex = 0; bgIndex < 2; bgIndex++)
    {
        for (int fgIndex = 0; fgIndex < COLOR_AMOUNT; fgIndex++)
        {
            int pairNumber = bgIndex * COLOR_AMOUNT + fgIndex;
            init_pair(pairNumber, foregroundColors[fgIndex], backgroundColors[bgIndex]);
        }
    }
}

void reset_terminal()
{
    endwin();
}

void text_color(int color)
{
    short pair;
    if (wattr_get(stdscr, NULL, &pair, NULL) == OK)
    {
        short backgroundBase = (pair / COLOR_AMOUNT) * COLOR_AMOUNT;
        attron(COLOR_PAIR(backgroundBase + color));
    }
}

void background_color(int color)
{
    short pair;
    if (wattr_get(stdscr, NULL, &pair, NULL) == OK)
    {
        short foregroundColor = pair % COLOR_AMOUNT;
        short backgroundBase = color * COLOR_AMOUNT;
        attron(COLOR_PAIR(backgroundBase + foregroundColor));
    }
}