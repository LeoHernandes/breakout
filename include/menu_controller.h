#ifndef MENU_CONTROLLER_H
#define MENU_CONTROLLER_H

#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include "Estruturas_Constantes.h"
#include "interface.h"
#include "terminal.h"

typedef enum
{
    NEW_GAME,
    LOAD_GAME,
    SCORES,
    QUIT,
} MenuOption;

void main_menu();

#endif
