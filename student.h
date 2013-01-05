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
#define ID_LENGTH 8
#define STD_MAX 10
#define CAT_LENGTH 1
#define LR_LENGTH 1

const char EMPTY_STRING[] = "\0";

//:TODO: Validacoes e restricoes
typedef enum {
    y = 'y', n = 'n'
} LicenseRev;

//:TODO: VALIDATE ID = 8 NUMBERS -- init= 99999999

typedef struct {
    unsigned char id[ID_LENGTH];
    Person person;
    LicenseRev licenserev;
} Student;

Student getLicenseRev(Student student) {
    char lr;
    Bool v = FALSE;
    
    do {
        if (lr == 'y' || lr == 'Y') {
            student.licenserev = y;
            v = TRUE;
        }else if (lr == 'n' || lr == 'N') { 
            student.licenserev = n;
            v = TRUE;
        }
    } while (v = FALSE);
        return student;
} 

//:TODO: Must do validations for licenserev

Student initStudentsFile(Student students[]) {
    unsigned short int i;
    
    for(i = 0; i < STD_MAX; i++){
        strcpy(students[i++].id, EMPTY_STRING);
    }
    return students[STD_MAX];
}

Student createStudentsFile(Student students[]) {
    int frtn;
    
    FILE *pStudents = fopen("students","w");
    if(pStudents == (FILE *) NULL){
        printf("Failed to create file");
    }else{
        frtn = fwrite(students, sizeof(Student), STD_MAX, pStudents);
    }
    return students[STD_MAX];
}

Student readStudentsFile(Student students[]) {
    int frtn, i;
    
    FILE *pStudents = fopen("students","r");
    if (pStudents == (FILE *) NULL){
        puts("Ficheiro nao existente.");
        puts("A criar ficheiro...");
        createStudentsFile(students);
        students[STD_MAX] = initStudentsFile(students);
        puts("Ficheiro criado.");
        readStudentsFile(students);
        for(i=0; i > STD_MAX; i++){
            printf("%d: %c", i, students[i].id);
        }
    }else{
        fread(students, sizeof(Student), STD_MAX, pStudents);
        fclose(pStudents);
    }
    
    return students[STD_MAX];
}


int searchFunction(Student students[]){
    int i, studentnr;
    
    for(i = 0; i < students[STD_MAX]; i++){
        
    } return studentnr;
}

Student insertStudent(Student students[], int studentnr) {
    printf("ID: ");
    fgets(students[studentnr].id, ID_LENGTH, stdin);
    clear_input();
    printf("Full name: ");
    fgets(students[studentnr].person.name, NAME_LENGTH, stdin);
    printf("Street: ");
    fgets(students[studentnr].person.address.street, NAME_LENGTH, stdin);
    printf("Door number: ");
    fgets(students[studentnr].person.address.number, DOOR_NR, stdin);
    clear_input();
    printf("Postalcode: ");
    fgets(students[studentnr].person.address.postalcode.postalcode, POSTALCODE, stdin);
    clear_input();
    printf("City: ");
    fgets(students[studentnr].person.address.city, CITY_LENGTH, stdin);
    printf("Phonenumber: ");
    fgets(students[studentnr].person.phonenr, PHONE_LENGTH, stdin);
    clear_input();
    printf("Birthday: (dia-mes-ano): ");
    scanf("%hu", &students[studentnr].person.date.tm_mday);
    scanf("%hu", &students[studentnr].person.date.tm_mon);
    scanf("%hu", &students[studentnr].person.date.tm_year);
    clear_input();
    printf("Category: (A, B, C ou D): ");
    getCat(students[studentnr].person);
    clear_input();
    printf("Revalidate license?(y ou n): ");
    scanf("%c", &students[studentnr].licenserev);
    printf("Student successfully added.%c", NEWLINE);
    
    return students[studentnr];
}

void alterar_aluno(Student students[], int studentnr) {
    
}

void listar_aluno() {

}

int studentMenu() {

    int stdopt;

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
        scanf("%d", &stdopt);
    } while (stdopt > 5 || stdopt < 1);

    return stdopt;
}

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* STUDENT_H */

