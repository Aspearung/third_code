#include <stdio.h>
#include <stdlib.h>
#define element int

typedef struct ung{
    element data;
    struct ung *link;
}ung;


typedef struct head{
    struct head *link;
}head;

void first_insert(ung *ung,head *head){
    ung->data = 0;
    ung->link = NULL;
    head->link = ung;
}

void insert_ung(head *head,element value){
    ung *p = (ung *)malloc(sizeof(ung));

    p->data = value;
    p->link = head->link;
    head->link = p;
}


void delete_ung(head *head){
    ung *p = (ung *)malloc(sizeof(ung));
    ung *removed = (ung *)malloc(sizeof(ung));


    removed = head->link;
    head->link = removed->link;
    if(removed->link == NULL){
        printf("error!\n");
        free(removed);
        return 0;
    }
    free(removed);
}

void print_ung(head *head){
    ung *p = (ung *)malloc(sizeof(ung));
    p = head->link;
    for(p;p != NULL; p = p->link){
        printf("%d ",p->data);
    }
}

void search_ung(head *head,element value){
    ung *p = (ung *)malloc(sizeof(ung));
    int i = 0;
    p = head->link;
    for(p;p != NULL; p = p->link){
        i++;
        if(p->data == value){
            printf("\nã���ô� %d�� %d��°�� �ֽ��ϴ�.\n ",value,i);
        }
    }
}

int main(void){

    ung  ung;
    head  head;
    int user,value;
    first_insert(&ung,&head);

    while(1){
        printf("\n1.���� 2.���� 3. Ž��: ");
        scanf("%d",&user);
        switch(user){
            case 1:{
                printf("1. ���� \n");
                printf("�Է� : ");
                scanf("%d",&value);
                insert_ung(&head,value);
                print_ung(&head);
                break;
            }

            case 2:{
                printf("2. ���� \n");
                delete_ung(&head);
                print_ung(&head);
                break;
            }

            case 3:{
                printf("3. Ž�� \n");
                printf("�Է� : ");
                scanf("%d",&value);
                search_ung(&head,value);
                print_ung(&head);
                break;
            }

            default :{
                printf("�߸��� �Է����� �����մϴ�!\n");
                break;
            }

        }
    }
}


