#include "hw4_1.h"

int main() {
    struct abonent* abonents =
        (struct abonent*)malloc(INITIAL_CAPACITY * sizeof(struct abonent));
    int abonentCount = 0;
    int capacity = INITIAL_CAPACITY;
    int choice;

    if (!abonents) {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    do {
        printf("\nMenu:\n");
        printf("1) Add Abonent\n");
        printf("2) Delete Abonent\n");
        printf("3) Search by Name\n");
        printf("4) Display All\n");
        printf("5) Exit\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case ADD_ABONENT:
                addAbonent(&abonents, &abonentCount, &capacity);
                break;
            case DELETE_ABONENT:
                deleteAbonent(&abonents, &abonentCount, &capacity);
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

    free(abonents);
    printf("Memory freed successfully.\n");

    exit(EXIT_FAILURE);
}
