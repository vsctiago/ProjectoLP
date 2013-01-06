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
#define INST_MAX 10
#define CAT_LENGTH 1
#define LR_LENGTH 1

const unsigned short int initINST = 9999;

typedef struct {
    unsigned short int licensenr;
    Person person;
    unsigned short salary;
} Instructor;

//:TODO: VALIDATIONS FOR LICENSENR

Instructor initInstructorFile(Instructor instructor[]) {
    unsigned short int i;

    for (i = 0; i < INST_MAX; i++) {
        instructor[i].licensenr = initINST;
    }
    return instructor[INST_MAX];
}

Instructor createInstructorFile(Instructor instructor[]) {
    int frtn;

    FILE *pInstructor = fopen("instructor", "w");
    if (pInstructor == (FILE *) NULL) {
        printf("Failed to create file");
    } else {
        frtn = fwrite(instructor, sizeof (Instructor), INST_MAX, pInstructor);
    }
    return instructor[INST_MAX];
}

Instructor readInstructorFile(Instructor instructor[]) {
    int frtn, i;

    FILE *pInstructor = fopen("instructor", "r");
    if (pInstructor == (FILE *) NULL) {
        puts("Ficheiro nao existente.");
        puts("A criar ficheiro...");
        createInstructorFile(instructor);
        instructor[INST_MAX] = initInstructorFile(instructor);
        puts("Ficheiro criado.");
        readInstructorFile(instructor);
        for (i = 0; i > INST_MAX; i++) {
            printf("%d: %c", i, instructor[i].licensenr);
        }
    } else {
        fread(instructor, sizeof (Instructor), INST_MAX, pInstructor);
        fclose(pInstructor);
    }
    return instructor[INST_MAX];
}

//:TODO: FINISH SEARCHFUNCTION

int searchInstructor(Instructor instructor[], unsigned int in) {
    int pos = 0, instructornr;

    while ((pos < INST_MAX) && (in != instructor[pos].licensenr)) {
        if (instructornr == in) {

        }
    }
    return instructornr;
}

Instructor insertInstructor(Instructor instructor[], int instructornr){
 
    printf("License: ");
    scanf("%lu", instructor[instructornr].licensenr);
    clear_input();
    printf("Full name: ");
    fgets(instructor[instructornr].person.name, NAME_LENGTH, stdin);
    printf("Street: ");
    fgets(instructor[instructornr].person.address.street, NAME_LENGTH, stdin);
    printf("Door number: ");
    fgets(instructor[instructornr].person.address.number, DOOR_NR, stdin);
    clear_input();
    printf("Postalcode: ");
    fgets(instructor[instructornr].person.address.postalcode.postalcode, POSTALCODE, stdin);
    clear_input();
    printf("City: ");
    fgets(instructor[instructornr].person.address.city, CITY_LENGTH, stdin);
    printf("Phonenumber: ");
    fgets(instructor[instructornr].person.phonenr, PHONE_LENGTH, stdin);
    clear_input();
    printf("Birthday: (dia-mes-ano): ");
    scanf("%hu", &instructor[instructornr].person.date.tm_mday);
    scanf("%hu", &instructor[instructornr].person.date.tm_mon);
    scanf("%hu", &instructor[instructornr].person.date.tm_year);
    clear_input();
    printf("Category: (A, B, C ou D): ");
    getCat(instructor[instructornr].person);
    clear_input();
    printf("Salary: ");
    scanf("%lu", instructor[instructornr].salary);
    printf("Instructor successfully added.%c", NEWLINE);

    return instructor[instructornr];

}

int menu_Instrutor() {

    int choice;

    do {
        printf("\t\t\t* Manage Instructor Data *\n\n");
        printf("                        |------------------|\n");
        printf("                        |1-Add\t|\n");
        printf("                        |2-Modify\t|\n");
        printf("                        |3-List\t|\n");
        printf("                        |4-Remove\t|\n");
        printf("                        |5-Back\t|\n");
        printf("                        |------------------|\n\n");
        printf("\nSelect an option: ");
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

