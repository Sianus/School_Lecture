#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    char data[4];
    struct node *link;
}node;

typedef node *list_pointer;

void insert(list_pointer *ptr, list_pointer node, char *t)
{
    list_pointer temp;
    temp = (list_pointer)malloc(sizeof(node));
    strcpy(temp->data, t);
    if(*ptr){
        temp->link = node->link;
        node->link=temp;
    }
    else {
        temp->link = NULL;
        *ptr=temp;
    }
}

void delete(list_pointer *ptr, list_pointer trail, list_pointer node)
{
    if(trail) trail->link=node->link;
    else *ptr=(*ptr)->link;
    free(node);
}

void print_list(list_pointer ptr)
{
    printf("\n------list-----\n");
    for(; ptr; ptr=ptr->link){
        printf("%4s", ptr->data);
        if(ptr->link) printf("\n");
    }
    printf("\n");
}

int main(void){
    list_pointer ptr=NULL;
    int num, node_c=0, index, i;
    char data[4];
    while(1){
        list_pointer temp;
        printf("1. Insert 2. Delete 3. Exit\n");
        scanf("%d", &num);
        if(num==3){
            printf("Exit the program");
            break;
        }
        if(num==1) {
            printf("Input Data : ");
            scanf("%s", data);
            if(node_c == 0)
            {
                temp=ptr;
                insert(&ptr, temp, data);
                node_c++;
            }
            else
            {
                printf("Where you want input data? : ");
                scanf("%d", &index);
                if(index>node_c+1) printf("You can input under %d index bb..\n", node_c+1);
                else if (index==1)
                {
                    temp=(list_pointer)malloc(sizeof(node));
                    strcpy(temp->data, data);
                    temp->link=ptr;
                    ptr=temp;
                    node_c++;
                }
                else{
                    temp=ptr;
                    for(i=2;i<index;i++) temp=temp->link;
                    insert(&ptr, temp, data);
                    node_c++;
                }
            }
        }
        else if(num==2)
        {
            if(node_c==0){
                printf("No Data in list");
                continue;
            }
            printf("Where located data you want to delete? : ");
            scanf("%d", &index);
            if(index==1){
                temp=ptr;
                ptr=ptr->link;
                free(temp);
                node_c--;
            }
            else if(index>node_c){
                printf("You can delete under %d index bb..", node_c);
                continue;
            }
            else{
                temp=ptr;
                for(i=2;i<index;i++) temp=temp->link;
                delete(&ptr, temp, temp->link);
                node_c--;
            }
        }
        else{
            printf("Plz input number between 1 to 3\n");
            continue;
        }
        print_list(ptr);
    }
}