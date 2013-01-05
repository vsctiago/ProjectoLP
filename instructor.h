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

