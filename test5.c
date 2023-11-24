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
            printf("\n찾으시는 %d는 %d번째에 있습니다.\n ",value,i);
        }
    }
}

int main(void){

    ung  ung;
    head  head;
    int user,value;
    first_insert(&ung,&head);

    while(1){
        printf("\n1.삽입 2.삭제 3. 탐색: ");
        scanf("%d",&user);
        switch(user){
            case 1:{
                printf("1. 삽입 \n");
                printf("입력 : ");
                scanf("%d",&value);
                insert_ung(&head,value);
                print_ung(&head);
                break;
            }

            case 2:{
                printf("2. 삭제 \n");
                delete_ung(&head);
                print_ung(&head);
                break;
            }

            case 3:{
                printf("3. 탐색 \n");
                printf("입력 : ");
                scanf("%d",&value);
                search_ung(&head,value);
                print_ung(&head);
                break;
            }

            default :{
                printf("잘못된 입력으로 종료합니다!\n");
                break;
            }

        }
    }
}


