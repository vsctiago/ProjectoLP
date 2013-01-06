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
#define PHONE_LENGTH 9

const char EMPTY_STRING[] = "\0";

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

//:TODO: VERIFY IF CATEGORY ENUM WORKING WITH STRUCT
typedef struct {
    unsigned char name[NAME_LENGTH];
    Address address;
    unsigned char phonenr[PHONE_LENGTH];
    Date date;
    Category category;
} Person;

Person getName(Person person) {
    
    printf("Full name: ");
    fgetsUpd(person.name, NAME_LENGTH);
    return person;
}

Person getAddress(Person person) {
    Bool v = FALSE;
    
    printf("*Address*");
    printf("%c", NEWLINE);
    printf("Street: ");
    fgetsUpd(person.address.street, STREET_LENGTH);
    printf("%c", NEWLINE);
    printf("Door number: ");
    fgetsUpd(person.address.number, DOOR_NR);
    printf("%c", NEWLINE);
    printf("PostalCode: ");
    fgetsUpd(person.address.postalcode, POSTALCODE);
    printf("%c", NEWLINE);
    printf("City: ");
    fgetsUpd(person.address.city, CITY_LENGTH);
    printf("%c", NEWLINE);
    return person;
}

Person getPhone(Person person) {
    Bool v = FALSE;
    
    printf("Phone number: ");
    fgetsUpd(person.phonenr, PHONE_LENGTH);
    printf("%c", NEWLINE);
    return person;
}

Person getBirthday(Person person) {
    Bool v = FALSE;
    
    printf("Birthday: ");
    scanf("%d", person.date.tm_mday);
    scanf("%d", person.date.tm_mon);
    scanf("%d", person.date.tm_year);
    printf("%c", NEWLINE);
    return person;
}

Person getCat(Person person) {
    char cat;
    Bool v = FALSE;
    
    do {
        scanf("%c", &cat);
        if(cat == 'a' || cat == 'A') {
            person.category = A;
            v = TRUE;
        } else if (cat == 'b' || cat == 'B') {
            person.category = B;
            v = TRUE;
        } else if (cat == 'c' || cat == 'C') {
            person.category = C;
            v = TRUE;
        } else if (cat == 'd' || cat == 'D') {
            person.category = D;
            v = TRUE;
        } else {
            puts("Invalid input.");
            puts("Insert a valid category!");
            v = FALSE;
            
        }
    } while (v == FALSE);
    return person;
}




#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* PERSON_H */

