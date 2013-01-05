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

#define NAME_LENGTH 80
#define STREET_LENGTH 60
#define CITY_LENGTH 20


//:TODO: Passar "unsigned" para "char" (vectores)
//:TODO: postalcode (como inserir "-" "traçinho")
typedef struct {
    char localnr[4], streetnr[3];
} PostalCode;

typedef struct {
    char street[STREET_LENGTH];
    unsigned short int number;
    PostalCode postalcode;
    char city[CITY_LENGTH];
} Address;

typedef struct tm Date;

typedef enum {
    A = 'A', B = 'B', C = 'C', D = 'D'
} Category;

//:TODO: Validacoes e restricoes
Category getCat() {
    char dc;
    
    if(dc == 'A')
    scanf("%c", &dc);
}

typedef struct {
    char name[NAME_LENGTH];
    Address address;
    unsigned long int phonenr;
    Date date;
    Category category;
} Person;


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* PERSON_H */

