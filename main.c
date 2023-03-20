#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>

typedef struct Node {
    char *item;
    struct Node *next;
} Node;

void push(Node **head, char *newElement) {
    Node *set = malloc(sizeof(Node));
    set->item = malloc(200 * sizeof(char));
    strcpy(set->item, newElement);
    set->next = *head;
    *head = set;
    printf("The element has been added\n");
}

int uniqueItem(Node *set, char *item) {
    bool work = true;

    for (Node *head = set; head != NULL; head = head->next) {
        if (strcmp(item, head->item) == 0) {
            work = false;
            printf("This element is already in the set\n");
            break;
        }
    }
    return work;
}

char *pop(Node **head) {
    Node *set = *head;
    char *result = set->item;
    *head = set->next;
    free(set);
    printf("The last element has been deleted\n");

    return result;
}

void printArr(Node *set) {
    while (set) {
        printf("%s ", set->item);
        set = set->next;
    }
    printf("\n");
}

int main() {
    Node *firstSet = NULL;
    Node *secondSet = NULL;
    char *item[200];
    int operation, setNumber;
    bool work = true;
    while (work == true) {
        printf("Choose:\n1. Add element\n2. Delete last element\n3. Show the set\n0. Exit\n");
        scanf("%d", &operation);

        if (operation != 0) {
            printf("Which set: 1 or 2?\n");
            scanf("%d", &setNumber);
        }

        switch (operation) {
            case 1:
                if (setNumber == 1) {
                    printf("Enter a new element\n");
                    scanf("%s", &item);
                    if (uniqueItem(firstSet, item))
                        push(&firstSet, item);
                } else if (setNumber == 2) {
                    printf("Enter a new element\n");
                    scanf("%s", &item);
                    if (uniqueItem(secondSet, item))
                        push(&secondSet, item);
                } else {
                    printf("Error. There are only 2 sets\n");
                }
                break;
            case 2:
                if (setNumber == 1) {
                    pop(&firstSet);
                } else if (setNumber == 2) {
                    pop(&secondSet);
                } else {
                    printf("Error. There are only 2 sets\n");
                }
                break;
            case 3:
                if (setNumber == 1) {
                    printArr(firstSet);
                } else if (setNumber == 2) {
                    printArr(secondSet);
                } else {
                    printf("Error. There are only 2 sets\n");
                }
                break;
            case 0:
                work = false;
                break;
            default:
                printf("Wrong operation. There is no such an option as %d\n", operation);
                break;
        }
    }

    return 0;
}

