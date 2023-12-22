#ifndef ABONENTLIST_H
#define ABONENTLIST_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define INITIAL_CAPACITY 10
#define NAME_SIZE 10
#define TEL_SIZE 10

struct abonent {
    char name[NAME_SIZE];
    char second_name[NAME_SIZE];
    char tel[TEL_SIZE];
};

enum MenuOptions {
    ADD_ABONENT = 1,
    DELETE_ABONENT,
    SEARCH_BY_NAME,
    DISPLAY_ALL,
    EXIT
};

enum RetutnsValue {
    SUCCESS = 1,
    FAIL = -1,
};

int addAbonent(struct abonent** abonents, int* abonentCount, int* capacity);
int deleteAbonent(struct abonent** abonents, int* abonentCount, int* capacity);
int searchByName(struct abonent* abonents, int abonentCount);
void displayAll(struct abonent* abonents, int abonentCount);

#endif