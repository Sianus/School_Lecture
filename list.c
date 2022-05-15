#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
    char data[4];
    struct node *link;
} node;
typedef node *list_pointer;

void insert(list_pointer *ptr, list_pointer x, char *t) {
    list_pointer temp;
    temp=(list_pointer)malloc(sizeof(node));
    strcpy(temp->data, t);
    if (*ptr) {
        temp->link=x->link;
        x->link=temp;
    }
    else {
        temp->link=NULL;
        *ptr=temp;
    }
}
void delete(list_pointer *ptr, list_pointer trail, list_pointer x) {
    if (trail) trail->link=x->link;
    else *ptr=(*ptr)->link;
    free(x);
}
void print_list(list_pointer ptr) {
    printf("\n----리스트----\n");
    for(; ptr ; ptr=ptr->link) {
        printf("%4s", ptr->data);
        if (ptr->link) printf("\n");
    }
    printf("\n");
}

int main(void) {
    list_pointer ptr=NULL;
    int flag, node_cnt=0, index, i;
    char data[4];
    while (1) {
        list_pointer temp;
        printf("1. 삽입 2. 삭제 3. 종료\n");
        scanf("%d", &flag);
        if (flag==3) { //종료
            printf("종료합니다.");
            break;
        }
        if (flag==1) { //추가
            printf("데이터 입력 : ");
            scanf("%s", data);
            if (node_cnt==0) { //리스트가 비어 있으면
                temp=ptr;
                insert(&ptr, temp, data);
                node_cnt=1;
            }
            else {
                printf("몇번째 노드에 추가할까요? : ");
                scanf("%d", &index);
                if (index>node_cnt+1) printf("%d 이하의 숫자만 가능합니다.\n", node_cnt+1);
                else if (index==1) { // 리스트의 맨 앞에 노드를 추가할 때
                    temp=(list_pointer)malloc(sizeof(node));
                    strcpy(temp->data, data);
                    temp->link=ptr;
                    ptr=temp;
                    node_cnt++;
                }
                else {
                    temp=ptr;
                    for(i=2;i<index;i++) temp=temp->link;
                    insert(&ptr, temp, data);
                    node_cnt++;
                }
            }
        }
        else if (flag==2) { //삭제
            if (node_cnt==0) { //리스트가 비어 있을 때
                printf("삭제할 노드가 없습니다.\n");
                continue;
            }
            printf("몇번째 노드를 삭제할까요? : ");
            scanf("%d", &index);
            if (index==1) { //리스트의 처음 노드를 삭제할 때
                temp=ptr;
                ptr=ptr->link;
                free(temp);
                node_cnt--;
            }
            else if (index>node_cnt) {
                printf("%d 이하의 숫자만 가능합니다.\n", node_cnt);
                continue;
            }
            else {
                temp=ptr;
                for(i=2;i<index;i++) temp=temp->link;
                delete(&ptr, temp, temp->link);
                node_cnt--;
            }
        }
        else {
            printf("없는 옵션입니다.\n");
            continue;
        }
        print_list(ptr);
    }
}
