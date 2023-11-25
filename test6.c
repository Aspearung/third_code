#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

void initializeList(LinkedList* list) {
    list->head = NULL;
}

void insertSorted(LinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;

    Node* current = list->head;
    Node* prev = NULL;

    while (current != NULL && current->data < value) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        prev->next = newNode;
        newNode->next = current;
    }
}

void deleteNode(LinkedList* list, int value) {
    Node* current = list->head;
    Node* prev = NULL;

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev == NULL) {
            list->head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }
}

void printList(const LinkedList* list) {
    const Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
}

int main(void) {
    LinkedList myList;
    initializeList(&myList);

    int userChoice, value;

    do {
        printf("\n1. ���� ����  2. ���� ����  3. ����Ʈ ���  4. ����\n");
        printf("����: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1: {
                printf("������ ������ �Է��ϼ���: ");
                scanf("%d", &value);
                insertSorted(&myList, value);
                break;
            }

            case 2: {
                printf("������ ������ �Է��ϼ���: ");
                scanf("%d", &value);
                deleteNode(&myList, value);
                break;
            }

            case 3:
                printf("���Ḯ��Ʈ ���: ");
                printList(&myList);
                break;

            case 4:
                printf("���α׷��� �����մϴ�.\n");
                break;

            default:
                printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n");
                break;
        }

    } while (userChoice != 4);

    freeList(&myList);

    return 0;
}
