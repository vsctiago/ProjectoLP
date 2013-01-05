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

// submenu "Gerir dados do Aluno"

// submenu "Gerir dados do Instrutor"

Student initStudentsFile(Student students[]){
    unsigned short int i;
    
    for(i = 0; i < STD_MAX; i++){
        strcpy(students[i++].id, EMPTY_STRING);
    }
    return students[STD_MAX];
}

void createStudentsFile(Student students[]) {
    int frtn;
    
    FILE *pStudents = fopen("students","w");
    if(pStudents == (FILE *) NULL){
        printf("Falha ao criar ficheiro");
    }else{
        frtn = fwrite(students, sizeof(Student), STD_MAX, pStudents);
    }
    return students[STD_MAX];
}

void studentsFile(Student students[]) {
    int frtn;
    
    FILE *pStudents = fopen("students","r");
    if (pStudents == (FILE *) NULL){
        puts("Ficheiro nao existente.");
        puts("A criar ficheiro...");
        createStudentsFile(students);
        students[STD_MAX] = initStudentsFile(students);
        studentsFile();
    }else{
        fread(students, sizeof(Student), STD_MAX, pStudents);
        fclose(pStudents);
    }
    
    return students[STD_MAX];
}

int main(void) {

    Student students[STD_MAX];
    int option, choice_students, i, studentnr = 0;


    do {
        option = menu();
        switch (option) {
            case 1:
                do {
                    choice_students = studentMenu();
                    students[STD_MAX] = studentsFile(students);
                    switch (choice_students) {
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
                } while (choice_students != 5);
            case 2:
                break;
            case 3:
                break;

        }
    } while (choice_students != 4);


    return 0;
}
