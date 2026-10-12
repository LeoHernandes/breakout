#ifndef MENU_H
#define MENU_H

void printa_moldura_main_menu();

int render_main_menu();

void printa_limpa_seta(int opcao, short acao);

void gera_opcao(int tecla, int *opcao);

void move_seta(int *opcao);

void printa_dificuldades();

void move_seta_dificuldade(int *opcao);

#endif
