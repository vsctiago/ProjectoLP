/* 
 * File:   instructor.h
 * Author: psycku
 *
 * Created on 4 de Janeiro de 2013, 19:42
 */

#ifndef INSTRUCTOR_H
#define	INSTRUCTOR_H

#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include "utilities.h"

typedef struct {
    unsigned short int licensenr;
    Person person;
    unsigned short salary;
} Instructor;

Instructor insertInstructor(Instructor Instructors[], int Instructornr){
    
}

int menu_Instrutor() {

    int choice;

    do {
        printf("\t\t\t* Gerir dados do Instrutor *\n\n");
        printf("Por Favor, escolha uma das seguintes opcoes digitanto o numero correspondente \n\n\n");
        printf("                        |------------------|\n");
        printf("                        |1-Adicionar dados |\n");
        printf("                        |2-Alterar dados   |\n");
        printf("                        |3-Listar dados    |\n");
        printf("                        |4-Remover dados   |\n");
        printf("                        |5-Voltar          |\n");
        printf("                        |------------------|\n\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &choice);
    } while (choice > 5 || choice < 1);

    return choice;
}

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* INSTRUCTOR_H */

