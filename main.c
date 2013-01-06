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
    int option, stdopt, stdmopt, studentnr = 0;

    do {
        option = menu();
    } while (option != 4);
    printf("Program closed.");
    return(EXIT_SUCCESS);
}
