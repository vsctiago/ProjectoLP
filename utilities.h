/* 
 * File:   utilities.h
 * Author: psycku
 *
 * Created on 4 de Janeiro de 2013, 20:22
 */

#ifndef UTILITIES_H
#define	UTILITIES_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    FALSE, TRUE
} Bool;

void clear_input() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void doclear(void) {
  int i;
  for (i = 0; i < 600; i++) {
    putchar('\n');
  }
  fflush(stdout);
}

int menu() {

    int option;

    do {
        printf("* Agenda eletronica *\n\n");
        printf("-- Bem vindo ao programa de agenciamento --\n \n \n ");
        printf("            ---------------------//---------------------\n\n");
        printf("Por Favor, escolha uma das seguintes opcoes digitanto o numero correspondente \n \n \n");
        printf("                        |-----------------------------|\n");
        printf("                        |1-Gerir dados do Aluno       |\n");
        printf("                        |2-Gerir dados do Instrutor   |\n");
        printf("                        |3-Gerir marcacoes das aulas  |\n");
        printf("                        |4-Sair                       |\n");
        printf("                        |-----------------------------|\n\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &option);
    } while (option > 4 || option < 1);

    return option;
}

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* UTILITIES_H */

