/* 
 * File:   student.h
 * Author: psycku
 *
 * Created on 4 de Janeiro de 2013, 19:28
 */

#ifndef STUDENT_H
#define	STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include "utilities.h"

//:TODO: Validacoes e restricoes
typedef enum {
    y = 'y', n = 'n'
} LicenseRev;

typedef struct {
    unsigned long int id;
    Person person;
    LicenseRev licenserev;
} Student;

//:DUVIDA: Preciso de por outro define aqui?

Student insertStudent(Student Students[], int studentnr) {
    puts("Inserir numero de identificacao: ");
    scanf("%lu", &Students[studentnr].id);
    clear_input();
    puts("Escrever nome completo: ");
    fgets(Students[studentnr].person.name, NAME_LENGTH, stdin);
    puts("Escrever o nome da rua onde habita: ");
    fgets(Students[studentnr].person.address.street, NAME_LENGTH, stdin);
    puts("Inserir numera da porta: ");
    scanf("%hu", &Students[studentnr].person.address.number);
    clear_input();
    puts("Inserir codigo postal: ");
    scanf("%hu - %hu", &Students[studentnr].person.address.postalcode.localnr, &Students[studentnr].person.address.postalcode.streetnr);
    clear_input();
    puts("Escrever a localidade onde habita: ");
    fgets(Students[studentnr].person.address.city, CITY_LENGTH, stdin);
    puts("Inserir numero de telefone: ");
    scanf("%lu", &Students[studentnr].person.phonenr);
    clear_input();
    puts("Inserir data de nascimento (dia-mes-ano): ");
    scanf("%hu", &Students[studentnr].person.date.tm_mday);
    scanf("%hu", &Students[studentnr].person.date.tm_mon);
    scanf("%hu", &Students[studentnr].person.date.tm_year);
    clear_input();
    puts("Introduzir a categoria de conducao na qual se esta a inscrever (A, B, C ou D): ");
    int Category = (intptr_t) & Students[studentnr].person.category;
    scanf("%d", &Category);
    clear_input();
    puts("Introduzir revalidacao de carta (sim ou nao): ");
    int LicenseRev = (intptr_t) & Students[studentnr].licenserev;
    scanf("%d", &LicenseRev);
    puts("Aluno adicionado com sucesso");
    
    return Students[studentnr];
}

int studentMenu() {

    int option;

    do {
        printf("\t\t\t* Gerir dados do Aluno *\n\n");
        printf("Por Favor, escolha uma das seguintes opcoes digitanto o numero correspondente \n\n\n");
        printf("                        |------------------|\n");
        printf("                        |1-Adicionar dados |\n");
        printf("                        |2-Alterar dados   |\n");
        printf("                        |3-Listar dados    |\n");
        printf("                        |4-Remover dados   |\n");
        printf("                        |5-Voltar          |\n");
        printf("                        |------------------|\n\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &option);
    } while (option > 5 || option < 1);

    return option;
}

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* STUDENT_H */

