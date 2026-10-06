#include <stdio.h>
#include <ncurses.h>
#include "Estruturas_Constantes.h"
#include "interface.h"
#include "terminal.h"

void printa_moldura_main_menu()
// printa a moldura que engloba o titulo do jogo
{
    int i;

    text_color(COLOR_MAGENTA);
    move_cursor_to(TITULO_XINI, TITULO_YINI);
    printf("%c", BORDA_SE); // canto superior esquerdo
    for (i = TITULO_XINI + 1; i < TITULO_XFIM; i++)
    {
        printf("%c", BARRA_H); // borda superior
    }
    printf("%c", BORDA_SD); // canto superior direito
    for (i = TITULO_YINI + 1; i < TITULO_YFIM; i++)
    {
        move_cursor_to(TITULO_XFIM, i);
        printf("%c", BARRA_V); // borda direita
    }

    move_cursor_to(TITULO_XINI, TITULO_YINI + 1);
    for (i = TITULO_YINI + 1; i < TITULO_YFIM; i++)
    {
        move_cursor_to(TITULO_XINI, i);
        printf("%c", BARRA_V); // borda esquerda
    }
    move_cursor_to(TITULO_XINI, TITULO_YFIM);
    printf("%c", BORDA_IE); // canto inferior esquerdo
    for (i = TITULO_XINI + 1; i < TITULO_XFIM; i++)
    {
        printf("%c", BARRA_H); // borda inferior
    }
    printf("%c", BORDA_ID); // canto inferior direito
}

void printa_help_main_menu()
{
    move_cursor_to(TITULO_XINI - 10, TITULO_YFIM + 18);
    text_color(COLOR_WHITE);
    printf("Pressione as setas para ");
    text_color(COLOR_MAGENTA);
    printf("CIMA ");
    text_color(COLOR_WHITE);
    printf("e para ");
    text_color(COLOR_MAGENTA);
    printf("BAIXO ");
    text_color(COLOR_WHITE);
    printf("para navegar no menu");
    move_cursor_to(TITULO_XINI - 10, TITULO_YFIM + 20);
    printf("Pressione ");
    text_color(COLOR_MAGENTA);
    printf("ENTER ");
    text_color(COLOR_WHITE);
    printf("para escolher a opcao");
}

int printa_main_menu()
// carrega o arquivo que tem a ilustracao do main menu e printa na tela
// retorna zero se houve erro, retorna 1 se foi feito com sucesso
{
    FILE *arq;
    char linha[STRINGAO];

    clear_screen(); // limpa a tela de qualquer funcao que estava executando antes
    if ((arq = fopen("main_menu.txt", "r")) == NULL)
    {
        limpa_erro_arquivo();
        print_text_at(XINI, YFIM + 1, "*** ERRO AO ABRIR O ARQUIVO DO MAIN_MENU ***");
        return 0;
    }

    text_color(COLOR_MAGENTA);
    while (!feof(arq))
    {
        if (fgets(linha, sizeof(linha), arq) == NULL)
        {
            limpa_erro_arquivo();
            print_text_at(XINI, YFIM + 1, "*** ERRO AO LER ARQUIVO DO MAIN_MENU ***");
            fclose(arq);
            return 0;
        }
        else
            printf("%s", linha);
    }
    fclose(arq);
    printa_moldura_main_menu();
    printa_help_main_menu();
    return 1;
}

int printa_creditos()
// abre o arquivo dos creditos e printa na tela
// retorna 0 se houve erro, devolve 1 se foi feito com sucesso
{
    FILE *arq;
    char linha[STRINGAO];

    if ((arq = fopen("creditos.txt", "r")) == NULL)
    {
        limpa_erro_arquivo();
        print_text_at(XINI, YFIM + 1, "*** ERRO AO ABRIR OS CREDITOS ***");
        return 0;
    }

    text_color(COLOR_GREEN);
    while (!feof(arq))
    {
        if (fgets(linha, sizeof(linha), arq) == NULL)
        {
            limpa_erro_arquivo();
            print_text_at(XINI, YFIM + 1, "*** ERRO AO ABRIR OS CREDITOS ***");
            fclose(arq);
            return 0;
        }
        printf("%s", linha);
    }
    fclose(arq);
    return 1;
}

void printa_limpa_seta(int opcao, short acao)
// dependendo do numero da opcao, printa uma seta na opcao no menu
// se a acao for o numero 1, mas limpa a seta se a acao for o numero 2
{
    // vai para a posicao correta de acordo com a opcao
    move_cursor_to(SETA_X, TITULO_YFIM + (opcao * 2));

    if (acao == 1)
    {
        text_color(COLOR_RED);
        printf(">>");
        // coloca a seta
    }
    else if (acao == 2)
        printf("  ");
    // apaga a seta
}

void gera_opcao(char tecla, int *opcao)
// verifica qual a proxima posicao da seta de
// acordo com o input do usuario
{
    switch (tecla)
    {
    case SETA_CIMA:
        // se a seta estiver na opcao 1, volta para baixo
        if (*opcao == 1)
            *opcao = 6;
        else
            (*opcao)--;
        break;
    case SETA_BAIXO:
        // se a seta estiver na opcao 4, volta pra cima
        if (*opcao == 6)
            *opcao = 1;
        else
            (*opcao)++;
    }
}

void move_seta(int *opcao)
// move a seta ate que o usuario pressione enter
// devolve por referencia a opcao que o usuario escolheu
{
    char tecla = 0;

    while (tecla != ENTER)
    {
        printa_limpa_seta(*opcao, 1);

        tecla = getch();
        if (tecla == NUMPAD || tecla == ESPECIAL)
        {
            tecla = getch();
            printa_limpa_seta(*opcao, 2);
            gera_opcao(tecla, opcao);
        }
    }
    // quando sair do loop, usuario apertou enter
}

void printa_instrucoes()
// mostra instrucoes para iniciar o jogo
{
    text_color(COLOR_RED);
    printf("\n\n               PARA UMA MELHOR EXPERIENCIA:                \n\n\n\n");
    text_color(COLOR_WHITE);
    printf(" Pressione o ");
    text_color(COLOR_MAGENTA);
    printf("BOTAO DIREITO");
    text_color(COLOR_WHITE);
    printf(" do mouse na aba do console e clique em\n\n");
    text_color(COLOR_GREEN);
    printf("  propriedades -> fontes -> fontes de varredura");
    text_color(COLOR_WHITE);
    printf(" e clique em ");
    text_color(COLOR_GREEN);
    printf("OK.\n\n");
    text_color(COLOR_WHITE);
    printf(" Logo apos, pressione ");
    text_color(COLOR_MAGENTA);
    printf("ALT + ENTER");
    text_color(COLOR_WHITE);
    printf(" no menu para entrar em tela cheia!\n\n\n\n");
    text_color(COLOR_RED);
    printf("                 BOA SORTE E DIVIRTA-SE!                ");
}

void printa_dificuldades()
// mostra no menu as dificuldades para o usuario escolher
{
    move_cursor_to(31, 11);
    text_color(COLOR_MAGENTA);
    printf("ESCOLHA UMA DIFICULDADE");
    move_cursor_to(40, 17);
    text_color(COLOR_YELLOW);
    printf("Facil");
    move_cursor_to(40, 19);
    text_color(COLOR_RED);
    printf("Medio");
    move_cursor_to(39, 21);
    text_color(COLOR_RED);
    printf("Dificil");
}

void gera_opcao_dificuldade(char tecla, int *opcao)
// verifica qual a proxima posicao da seta de
// acordo com o input do usuario
{
    switch (tecla)
    {
    case SETA_CIMA:
        // se a seta estiver na opcao 1, volta para baixo
        if (*opcao == 1)
            *opcao = 3;
        else
            (*opcao)--;
        break;
    case SETA_BAIXO:
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
    char tecla = 0;

    while (tecla != ENTER)
    {
        printa_limpa_seta(*opcao, 1);

        tecla = getch();
        if (tecla == NUMPAD || tecla == ESPECIAL)
        {
            tecla = getch();
            printa_limpa_seta(*opcao, 2);
            gera_opcao_dificuldade(tecla, opcao);
        }
    }
    // quando sair do loop, usuario apertou enter
}
