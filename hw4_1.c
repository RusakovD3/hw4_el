#include <stdio.h>
#include <string.h>

#define MAX_ABONENTS 100

struct abonent {
    char name[10];
    char second_name[10];
    char tel[10];
};

enum MenuOptions {
    ADD_ABONENT = 1,
    DELETE_ABONENT,
    SEARCH_BY_NAME,
    DISPLAY_ALL,
    EXIT
};

void addAbonent(struct abonent* abonents, int* abonentCount);
void deleteAbonent(struct abonent* abonents, int* abonentCount);
void searchByName(struct abonent* abonents, int abonentCount);
void displayAll(struct abonent* abonents, int abonentCount);

int main() {
    struct abonent abonents[MAX_ABONENTS];
    int abonentCount = 0;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1) Add Abonent\n");
        printf("2) Delete Abonent\n");
        printf("3) Search by Name\n");
        printf("4) Display All\n");
        printf("5) Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case ADD_ABONENT:
                addAbonent(abonents, &abonentCount);
                break;
            case DELETE_ABONENT:
                deleteAbonent(abonents, &abonentCount);
                break;
            case SEARCH_BY_NAME:
                searchByName(abonents, abonentCount);
                break;
            case DISPLAY_ALL:
                displayAll(abonents, abonentCount);
                break;
            case EXIT:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != EXIT);

    return 0;
}

void addAbonent(struct abonent* abonents, int* abonentCount) {
    if (*abonentCount < MAX_ABONENTS) {
        printf("Enter name: ");
        scanf("%s", abonents[*abonentCount].name);

        printf("Enter second name: ");
        scanf("%s", abonents[*abonentCount].second_name);

        printf("Enter telephone number: ");
        scanf("%s", abonents[*abonentCount].tel);

        ++(*abonentCount);
        printf("Abonent added successfully.\n");
    } else
        printf("Abonent directory is full. Cannot add more abonents.\n");
}

void deleteAbonent(struct abonent* abonents, int* abonentCount) {
    char nameToDelete[10];
    int found = 0;

    printf("Enter name to delete: ");
    scanf("%s", nameToDelete);

    for (int i = 0; i < *abonentCount; ++i) {
        if (strcmp(abonents[i].name, nameToDelete) == 0) {
            memset(&abonents[i], 0, sizeof(struct abonent));
            found = 1;
            printf("Abonent deleted successfully.\n");
            break;
        }
    }

    if (!found)
        printf("Abonent not found.\n");
}

void searchByName(struct abonent* abonents, int abonentCount) {
    char nameToSearch[10];
    int found = 0;

    printf("Enter name to search: ");
    scanf("%s", nameToSearch);

    printf("Matching abonents:\n");
    for (int i = 0; i < abonentCount; ++i) {
        if (strcmp(abonents[i].name, nameToSearch) == 0) {
            printf("Name: %s, Second Name: %s, Telephone: %s\n", abonents[i].name, abonents[i].second_name, abonents[i].tel);
            found = 1;
        }
    }

    if (!found)
        printf("No matching abonents found.\n");
}

void displayAll(struct abonent* abonents, int abonentCount) {
    printf("All abonents:\n");
    for (int i = 0; i < abonentCount; ++i)
        if (abonents[i].name[0] != '\0')
            printf("Name: %s, Second Name: %s, Telephone: %s\n", abonents[i].name, abonents[i].second_name, abonents[i].tel);
}
