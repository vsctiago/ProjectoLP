/* 
 * File:   main.c
 * Author: PC
 *
 * Created on 21 de Dezembro de 2012, 23:57
 */


#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include "student.h"
#include "instructor.h"
#include "utilities.h"
#define SCALE 50
#define CITYSIZE 20
/*
 * 
 */
int main() {

    Student students[STD_MAX];
    int option, stdopt, stdmopt, i, studentnr = 0;


    do {
        option = menu();
        switch (option) {
            case 1:
                do {
                    students[STD_MAX] = readStudentsFile(students);
                    stdopt = studentMenu(students, studentnr);
                    switch (stdopt) {
                        case 1:
                            insertStudent(students, studentnr);
                            break;
                        case 2:
                            studentModifyMenu();
                            break;
                        case 3:
                            printf("List of students: ");
                            printf("%c", NEWLINE);
                            for (i = 0; i < STD_MAX; i++) {
                                printf("%d - %s", i, students[i].person.name);
                            }

                            break;
                        case 4:

                            break;
                        case 0:
                            printf("Seleccionada opcao 0 - Voltar\n");
                            break;
                    }
                } while (stdopt != 5);
            case 2:
                break;
            case 3:
                break;

        }
    } while (stdopt != 4);


    return(EXIT_SUCCESS);
}
