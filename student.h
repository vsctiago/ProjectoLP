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
#define STD_MAX 20
#define CAT_LENGTH 1
#define LR_LENGTH 1

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

Student getId(Student student) {
    Bool v = FALSE;
    
    printf("ID: ");
    fgetsUpd(student.id, ID_LENGTH);
    printf("%c", NEWLINE);
    return student;
}

Student getLicenseRev(Student student) {
    char lr;
    Bool v = FALSE;
    
    do {
        printf("Revalidate license?(y or n): ");
        scanf("%c", &student.licenserev);
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

int searchStudent(Student students[], unsigned int sn) {
    int pos = 0;
    
    while ((pos < STD_MAX) && (sn != students[pos].id)) {
        pos++;
    }
    if (pos != STD_MAX) {
        return pos;
        }else{
        return EOF;
        }
}

int studentMenu() {
    int option;

    do {
        printf("\t\t\t* Manage Student Data *\n\n");
        printf("\t\t\t   |------------------|\n");
        printf("\t\t\t   |     1-Add        |\n");
        printf("\t\t\t   |     2-Modify     |\n");
        printf("\t\t\t   |     3-List       |\n");
        printf("\t\t\t   |     4-Remove     |\n");
        printf("\t\t\t   |     5-Back       |\n");
        printf("\t\t\t   |------------------|\n\n\n");
        printf("Select an option: ");
        scanf("%d", &option);
    } while (option > 5 || option < 1);
    return option;
}

Student insertStudent(Student students[], int studentnr) {
    students[studentnr] = getId(students[studentnr]);
    students[studentnr].person = getName(students[studentnr].person);
    students[studentnr].person = getAddress(students[studentnr].person);
    students[studentnr].person = getPhone(students[studentnr].person);
    students[studentnr].person = getBirthday(students[studentnr].person);
    students[studentnr].person = getCat(students[studentnr].person);
    students[studentnr] = getLicenseRev(students[studentnr]);
    printf("Student successfully added.%c", NEWLINE);
    
    return students[studentnr];
}

void modifyStudent(Student students[], int studentnr) {
    
}

void listStudent() {

}


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* STUDENT_H */

