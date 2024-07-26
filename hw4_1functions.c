#include "hw4_1.h"

int addAbonent(struct abonent** abonents, int* abonentCount, int* capacity) {
    if (*abonentCount == *capacity) {
        int newCapacity = *capacity * 2;
        struct abonent* temp = (struct abonent*)realloc(
            *abonents, newCapacity * sizeof(struct abonent));
        if (!temp) {
            printf("Failed to allocate memory.\n");
            return FAIL;
        }
        *capacity = newCapacity;
        *abonents = temp;
    }

    printf("Enter name: ");
    if (scanf("%9s", (*abonents)[*abonentCount].name) != 1) {
        printf("Invalid input.\n");
        return FAIL;
    }

    printf("Enter second name: ");
    if (scanf("%9s", (*abonents)[*abonentCount].second_name) != 1) {
        printf("Invalid input.\n");
        return FAIL;
    }

    printf("Enter telephone number: ");
    if (scanf("%9s", (*abonents)[*abonentCount].tel) != 1) {
        printf("Invalid input.\n");
        return FAIL;
    }

    ++(*abonentCount);
    printf("Abonent added successfully.\n");
    return SUCCESS;
}

int deleteAbonent(struct abonent** abonents, int* abonentCount, int* capacity) {
    if (*abonentCount == 0) {
        printf("Abonent directory is empty.\n");
        return FAIL;
    }

    char nameToDelete[NAME_SIZE];
    printf("Enter name to delete: ");
    if (scanf("%9s", nameToDelete) != 1) {
        printf("Invalid input.\n");
        return FAIL;
    }

    int foundIndex = -1;
    for (int i = 0; i < *abonentCount; ++i) {
        if (strcmp((*abonents)[i].name, nameToDelete) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Abonent not found.\n");
        return FAIL;
    }

    for (int i = foundIndex; i < *abonentCount - 1; ++i) {
        (*abonents)[i] = (*abonents)[i + 1];
    }

    --(*abonentCount);

    if (*abonentCount > 0 && *abonentCount <= *capacity / 4) {
        *capacity /= 2;
        struct abonent* temp = (struct abonent*)realloc(
            *abonents, (*capacity) * sizeof(struct abonent));
        if (!temp && *abonentCount > 0) {
            printf("Failed to reallocate memory, but data is still intact.\n");
            return FAIL;
        }
        *abonents = temp;
    }

    printf("Abonent deleted successfully.\n");
    return SUCCESS;
}

int searchByName(struct abonent* abonents, int abonentCount) {
    char nameToSearch[NAME_SIZE];
    printf("Enter name to search: ");
    if (scanf("%9s", nameToSearch) != 1) {
        printf("Invalid input.\n");
        return FAIL;
    }

    int found = 0;
    printf("Matching abonents:\n");
    for (int i = 0; i < abonentCount; ++i) {
        if (strcmp(abonents[i].name, nameToSearch) == 0) {
            printf("Name: %s, Second Name: %s, Telephone: %s\n",
                   abonents[i].name, abonents[i].second_name, abonents[i].tel);
            found = 1;
        }
    }

    if (!found) printf("No matching abonents found.\n");

    return SUCCESS;
}

void displayAll(struct abonent* abonents, int abonentCount) {
    printf("All abonents:\n");
    for (int i = 0; i < abonentCount; ++i) {
        printf("Name: %s, Second Name: %s, Telephone: %s\n", abonents[i].name,
               abonents[i].second_name, abonents[i].tel);
    }
}