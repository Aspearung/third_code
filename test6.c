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
        fprintf(stderr, "메모리 할당 오류\n");
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
        printf("\n1. 숫자 삽입  2. 숫자 삭제  3. 리스트 출력  4. 종료\n");
        printf("선택: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1: {
                printf("삽입할 정수를 입력하세요: ");
                scanf("%d", &value);
                insertSorted(&myList, value);
                break;
            }

            case 2: {
                printf("삭제할 정수를 입력하세요: ");
                scanf("%d", &value);
                deleteNode(&myList, value);
                break;
            }

            case 3:
                printf("연결리스트 출력: ");
                printList(&myList);
                break;

            case 4:
                printf("프로그램을 종료합니다.\n");
                break;

            default:
                printf("잘못된 선택입니다. 다시 입력해주세요.\n");
                break;
        }

    } while (userChoice != 4);

    freeList(&myList);

    return 0;
}
