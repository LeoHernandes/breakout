#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include "Estruturas_Constantes.h"
#include "interface.h"
#include "terminal.h"

void printa_limpa_seta(int opcao, short acao)
// dependendo do numero da opcao, printa uma seta na opcao no menu
// se a acao for o numero 1, mas limpa a seta se a acao for o numero 2
{
    if (acao == 1)
    {
        text_color(COLOR_RED);
        print_text_at(SETA_X, TITULO_YFIM + (opcao * 2), ">>");
        // coloca a seta
    }
    else if (acao == 2)
        print_text_at(SETA_X, TITULO_YFIM + (opcao * 2), "  ");
    // apaga a seta
}

void gera_opcao(int tecla, int *opcao)
{
    switch (tecla)
    {
    case KEY_UP:
        // se a seta estiver na opcao 1, volta para baixo
        if (*opcao == 1)
            *opcao = 4;
        else
            (*opcao)--;
        break;
    case KEY_DOWN:
        // se a seta estiver na opcao 4, volta pra cima
        if (*opcao == 4)
            *opcao = 1;
        else
            (*opcao)++;
    }
}

void move_seta(int *opcao)
// move a seta ate que o usuario pressione enter
// devolve por referencia a opcao que o usuario escolheu
{
    int tecla = 0;

    while (tecla != '\n' && tecla != '\r' && tecla != KEY_ENTER)
    {
        printa_limpa_seta(*opcao, 1);

        wrefresh(stdscr);
        tecla = getch();
        if (tecla == KEY_UP || tecla == KEY_DOWN)
        {
            printa_limpa_seta(*opcao, 2);
            gera_opcao(tecla, opcao);
        }
    }
}

void printa_dificuldades()
// mostra no menu as dificuldades para o usuario escolher
{
    text_color(COLOR_MAGENTA);
    print_text_at(31, 11, "ESCOLHA UMA DIFICULDADE");
    text_color(COLOR_YELLOW);
    print_text_at(40, 17, "Facil");
    print_text_at(40, 19, "Medio");
    text_color(COLOR_RED);
    print_text_at(39, 21, "Dificil");
}

void gera_opcao_dificuldade(int tecla, int *opcao)
// verifica qual a proxima posicao da seta de
// acordo com o input do usuario
{
    switch (tecla)
    {
    case KEY_UP:
        // se a seta estiver na opcao 1, volta para baixo
        if (*opcao == 1)
            *opcao = 3;
        else
            (*opcao)--;
        break;
    case KEY_DOWN:
        // se a seta estiver na opcao 4, volta pra cima
        if (*opcao == 3)
            *opcao = 1;
        else
            (*opcao)++;
    }
}

void move_seta_dificuldade(int *opcao)
// move a seta ate que o usuario pressione enter
// devolve por referencia a dificuldade que o usuario escolheu
{
    int tecla = 0;

    while (tecla != '\n' && tecla != '\r' && tecla != KEY_ENTER)
    {
        printa_limpa_seta(*opcao, 1);

        wrefresh(stdscr);
        tecla = getch();
        if (tecla == KEY_UP || tecla == KEY_DOWN)
        {
            printa_limpa_seta(*opcao, 2);
            gera_opcao_dificuldade(tecla, opcao);
        }
    }
    // quando sair do loop, usuario apertou enter
}
