#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data; // 값을 저장할 변수 지정. 이번 실험은 정수형만을 대상으로 함으로 int형으로 지정. 하나의 node라고 생각해도 무방.
    struct node *link; // 연결 리스트의 특징으로, 다음 리스트의 주소를 지정하기 위한 명령어
}list_node;

// typedef 재정의 할 자료형  자료형 이름
typedef list_node *list_ptr; // list_node 의 포인터 타입을 list_ptr로 재정의

void insert_first(list_ptr *last, list_ptr node) // 원형 리스트에서 앞 쪽에 값을 넣는 것으로, 마지막 link 주소와 삽입하려는 값을 인자로 받는다.
{
    if(!(*last)) // last의 주소가 0(NULL)이 아니라면 실행
    {
        *last=node; // last가 가리키는 곳에 node 값을 대입
        node->link=node; // link에 다음 node를 지정(?)
    }
    else
    {
        node->link=(*last)->link;
        (*last)->link=node;
    }
}
void insert_last(list_ptr *last, list_ptr node)
{
    if(!(*last))
    {
        *last=node;
        node->link=node;
    }
    else
    {
        node->link=(*last)->link;
        (*last)->link=node;
        *last=node;
    }
}
int length(list_ptr last) // 연결 리스트의 길이
{
    list_ptr temp; int count=0;
    if(last){
        temp=last;
        do{
            count++;
            temp=temp->link;
        }while(temp!=last);
    }
    return count;
}
void insert_back(list_ptr *last, list_ptr node, int data)
{
    list_ptr temp=*last;
    while(temp->data!=data) temp=temp->link;
    node->link=temp->link;
    temp->link=node;
}
void printl(list_ptr last)
{
    list_ptr temp=last->link;
    while(temp)
    {
        printf("%d -> ", temp->data);
        temp=temp->link;
        if(temp==last)
        {
            printf("%d\n", temp->data);
            break;
        }
    }
}

int main(void)
{
    list_ptr last=NULL, temp;
    int i;
    for(i=2;i<=20; i+=2)
    {
        temp=(list_ptr)malloc(sizeof(list_node));
        temp->data=i;
        insert_last(&last, temp);
    }
    printl(last);
    
    temp=(list_ptr)malloc(sizeof(list_node));
    temp->data=1;

    insert_first(&last, temp);
    printl(last);
    temp=(list_ptr)malloc(sizeof(list_node));
    temp->data=21;

    insert_last(&last, temp);
    printl(last);
    temp=(list_ptr)malloc(sizeof(list_node));
    temp->data=11;

    insert_back(&last, temp, 18);
    printl(last);
}