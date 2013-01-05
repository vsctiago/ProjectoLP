/* 
 * File:   person.h
 * Author: psycku
 *
 * Created on 4 de Janeiro de 2013, 18:25
 */

#ifndef PERSON_H
#define	PERSON_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utilities.h"

#define NAME_LENGTH 80
#define STREET_LENGTH 60
#define CITY_LENGTH 20
#define DOOR_NR 3
#define POSTALCODE 8

typedef struct tm Date;

//:TODO: Passar "unsigned" para "char" (vectores)
typedef struct {
    unsigned char postalcode[POSTALCODE];
} PostalCode;

typedef struct {
    unsigned char street[STREET_LENGTH];
    unsigned char number[DOOR_NR];
    PostalCode postalcode;
    unsigned char city[CITY_LENGTH];
} Address;

typedef enum {
    A = 'A', B = 'B', C = 'C', D = 'D'
} Category;

typedef struct {
    char name[NAME_LENGTH];
    Address address;
    unsigned long int phonenr;
    Date date;
    Category category;
} Person;

Person getCat(Person person) {
    char cat;
    Bool v = FALSE;
    
    do {
        if(cat == 'a' || cat == 'A') {
            puts("Invalid input.");
            person.category = A;
            v = TRUE;
        } else if (cat == 'b' || cat == 'B') {
            puts("Invalid input.");
            person.category = B;
            v = TRUE;
        } else if (cat == 'c' || cat == 'C') {
            puts("Invalid input.");
            person.category = C;
            v = TRUE;
        } else if (cat == 'd' || cat == 'D') {
            puts("Invalid input.");
            person.category = D;
            v = TRUE;
        } else {
            puts("Insert a valid category!");
        }
    } while (v = FALSE);
    return person;
}




#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* PERSON_H */

