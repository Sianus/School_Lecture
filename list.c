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
    printf("\n----����Ʈ----\n");
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
        printf("1. ���� 2. ���� 3. ����\n");
        scanf("%d", &flag);
        if (flag==3) { //����
            printf("�����մϴ�.");
            break;
        }
        if (flag==1) { //�߰�
            printf("������ �Է� : ");
            scanf("%s", data);
            if (node_cnt==0) { //����Ʈ�� ��� ������
                temp=ptr;
                insert(&ptr, temp, data);
                node_cnt=1;
            }
            else {
                printf("���° ��忡 �߰��ұ��? : ");
                scanf("%d", &index);
                if (index>node_cnt+1) printf("%d ������ ���ڸ� �����մϴ�.\n", node_cnt+1);
                else if (index==1) { // ����Ʈ�� �� �տ� ��带 �߰��� ��
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
        else if (flag==2) { //����
            if (node_cnt==0) { //����Ʈ�� ��� ���� ��
                printf("������ ��尡 �����ϴ�.\n");
                continue;
            }
            printf("���° ��带 �����ұ��? : ");
            scanf("%d", &index);
            if (index==1) { //����Ʈ�� ó�� ��带 ������ ��
                temp=ptr;
                ptr=ptr->link;
                free(temp);
                node_cnt--;
            }
            else if (index>node_cnt) {
                printf("%d ������ ���ڸ� �����մϴ�.\n", node_cnt);
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
            printf("���� �ɼ��Դϴ�.\n");
            continue;
        }
        print_list(ptr);
    }
}
