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

const unsigned short int initINST = 10000;

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

int searchInstructor(Instructor instructors[], unsigned int in) {
    int pos = 0;
    
    while ((pos < INST_MAX) && (in != instructors[pos].licensenr)) {
        pos++;
    }
    if (pos != INST_MAX) {
        return pos;
        }else{
        return EOF;
        }
}

Instructor insertInstructor(Instructor instructor[], int instructornr){
 
    printf("License: ");
    scanf("%lu", instructor[instructornr].licensenr);
    clearInput();
    printf("Full name: ");
    fgets(instructor[instructornr].person.name, NAME_LENGTH, stdin);
    printf("Street: ");
    fgets(instructor[instructornr].person.address.street, NAME_LENGTH, stdin);
    printf("Door number: ");
    fgets(instructor[instructornr].person.address.number, DOOR_NR, stdin);
    clearInput();
    printf("Postalcode: ");
    fgets(instructor[instructornr].person.address.postalcode, POSTALCODE, stdin);
    clearInput();
    printf("City: ");
    fgets(instructor[instructornr].person.address.city, CITY_LENGTH, stdin);
    printf("Phonenumber: ");
    fgets(instructor[instructornr].person.phonenr, PHONE_LENGTH, stdin);
    clearInput();
    printf("Birthday: (dia-mes-ano): ");
    scanf("%hu", &instructor[instructornr].person.date.tm_mday);
    scanf("%hu", &instructor[instructornr].person.date.tm_mon);
    scanf("%hu", &instructor[instructornr].person.date.tm_year);
    clearInput();
    printf("Category: (A, B, C ou D): ");
    getCat(instructor[instructornr].person);
    clearInput();
    printf("Salary: ");
    scanf("%lu", instructor[instructornr].salary);
    printf("Instructor successfully added.%c", NEWLINE);

    return instructor[instructornr];

}

int menuInstrutor() {
    int option;

    do {
        printf("\t\t\t* Manage Instructor Data *\n\n");
        printf("\t\t\t   |------------------|\n");
        printf("\t\t\t   |     1-Add        |\n");
        printf("\t\t\t   |     2-Modify     |\n");
        printf("\t\t\t   |     3-List       |\n");
        printf("\t\t\t   |     4-Remove     |\n");
        printf("\t\t\t   |     5-Back       |\n");
        printf("\t\t\t   |------------------|\n");
        printf("Select an option: ");
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

#endif	/* INSTRUCTOR_H */

