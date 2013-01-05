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
#define STD_MAX 10
#define INST_MAX 10

const char EMPTY_STRING[] = "\0";
/*
 * 
 */
void alterar_aluno(Student alunos[], int nr_aluno) {

}

void listar_aluno() {

}

// Funcao para adicionar instrutores
Instructor insertInstructor(Instructor Instructors[], int Instructornr){
    
}

Student initStudentsFile(Student students[]){
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
        printf("Falha ao criar ficheiro");
    }else{
        frtn = fwrite(students, sizeof(Student), STD_MAX, pStudents);
    }
    return students[STD_MAX];
}

Student studentsFile(Student students[]) {
    int frtn, i;
    
    FILE *pStudents = fopen("students","r");
    if (pStudents == (FILE *) NULL){
        puts("Ficheiro nao existente.");
        puts("A criar ficheiro...");
        createStudentsFile(students);
        students[STD_MAX] = initStudentsFile(students);
        puts("Ficheiro criado.");
        studentsFile(students);
        for(i=0; i > STD_MAX; i++){
            printf("%d: %c", i, students[i].id);
        }
    }else{
        fread(students, sizeof(Student), STD_MAX, pStudents);
        for(i=0; i < STD_MAX; i++){
            printf("%d: %s", i, students[i].id);
        }
        fclose(pStudents);
    }
    
    return students[STD_MAX];
}

int main(void) {

    Student students[STD_MAX];
    int option, stdopt, i, studentnr = 0;


    do {
        option = menu();
        switch (option) {
            case 1:
                do {
                    stdopt = studentMenu();
                    students[STD_MAX] = studentsFile(students);
                    switch (stdopt) {
                        case 1:
                            puts("Selecionada opcao 1 - Adicionar dados");
                            insertStudent(students, studentnr);
                            break;
                        case 2:

                            break;
                        case 3:
                            puts("Selecionada opcao 3 - Listar dados");
                            puts("Alunos inscritos:");
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


    return 0;
}
