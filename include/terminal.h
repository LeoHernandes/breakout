#ifndef TERMINAL_H
#define TERMINAL_H

#include <ncurses.h>

void move_cursor_to(int x, int y);
void sleep(int milliseconds);
void clear_screen();
int keyboard_hit();
void print_char_at(int x, int y, chtype character);
void print_text_at(int x, int y, const char *text);
void setup_terminal();
void text_color(int color);

#endif