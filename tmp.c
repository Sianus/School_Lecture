#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    char data[4];
    struct node *link;
}node;

typedef node *list_pointer;
list_pointer ptr=NULL;

void creatList(char *t)
{
    ptr=(list_pointer)malloc(sizeof(node));
    strcpy(ptr->data, t);
    ptr->link=NULL;
}
void insert_(char *data, int index)
{
    int i;
    list_pointer temp;
    temp = (list_pointer)malloc(sizeof(node));
    strcpy(temp->data, data);
    if(index==1)
    {
        temp->link = ptr;
        ptr=temp;
        return;
    }
    temp->link=NULL;

}
void delete_(int index)
{
    if(index)
}

int main(void)
{
    int i,count = 0;
    char data[4];
    while(i!=3)
    {
        printf("\n1.Insert 2.Delete 3.Exit\n");
        scanf("%d", &i);
        switch(i)
        {
            case 1:
                if(count == 0)
                {
                    creatList(data);
                    print_list();
                    count++;
                }
        }
    }
}
