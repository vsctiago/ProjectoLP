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

Instructor initInstructorFile(Instructor instructor[]) {
    unsigned short int i;

    for (i = 0; i < INST_MAX; i++) {
        instructor[i].licensenr = initINST;
    }
    return instructor[INST_MAX];
}

Instructor insertInstructor(Instructor Instructors[], int Instructornr){
    
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

