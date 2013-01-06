/* 
 * File:   utilities.h
 * Author: psycku
 *
 * Created on 4 de Janeiro de 2013, 20:22
 */

#ifndef UTILITIES_H
#define	UTILITIES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NEWLINE '\n'

typedef enum {
    FALSE, TRUE
} Bool;

Bool fgetsUpd(char * const sentence, const unsigned int size) {
    unsigned int sSiz;

    if (fgets(sentence, size, stdin) != NULL) {    
        sSiz = strlen(sentence) - 1;
        if (sentence[sSiz] == NEWLINE) {
            sentence[sSiz] = '\0';
        } else {
            return TRUE;
        }
    }else {
        return FALSE;
    }
}

void clearInput() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void doClear(void) {
  int i;
  for (i = 0; i < 600; i++) {
    putchar('\n');
  }
  fflush(stdout);
}

int menu() {
    int option;

    do {
        printf("\t\t   * Welcome to the program agency *\n\n");
        printf("\t\t   |-------------------------------|\n");
        printf("\t\t   |    1-Manage Student Data      |\n");
        printf("\t\t   |    2-Manage Instructor Data   |\n");
        printf("\t\t   |    3-Manage Markings Lessons  |\n");
        printf("\t\t   |    4-Exit                     |\n");
        printf("\t\t   |-------------------------------|\n");
        printf("Select an option: ");
        scanf("%d", &option);
    } while (option > 4 || option < 1);
    return option;
}

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* UTILITIES_H */

