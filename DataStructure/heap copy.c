#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200



typedef struct{
    int key; // node의 data
}element;


typedef struct{
    element heap[MAX_ELEMENT]; // key 값을 가지는 것들의 배열이며, 배열 이름이 heap
    int heap_size; // heap의 크기
}HeapType;

HeapType* create()
{
    return (HeapType*)malloc(sizeof(HeapType)); // heap을 저장하기 위해 공간 할당
}

void init(HeapType* h)
{
    h->heap_size=0; // heap을 초기화하는데, 처음에는 그 크기가 0
}

void insert_max_heap(HeapType* h, element item)
{
    int i;
    i=++(h->heap_size);
    while((i!=1)&&(item.key > h->heap[i/2].key))
    {
        h->heap[i]=h->heap[i/2];
        i/=2;
    }
    h->heap[i]=item;
}

element delete_max_heap(HeapType *h){ 
	int parent,child;
	element item, temp;

	item=h->heap[1]; 
	temp=h->heap[(h->heap_size)--];
	parent=1;
	child=2;

	while(child <= h->heap_size){
		if((child<h->heap_size) &&((h->heap[child].key)<h->heap[child+1].key))
        {
    		child++;
		}
		if(temp.key >= h->heap[child].key) {
			break; 
		} 
		h->heap[parent]=h->heap[child];
		h->heap[parent]=h->heap[child];
		parent=child;
		child*=2;
	}
	h->heap[parent]=temp; 
	return item;
}

void for_heap(element x[], int n)
{
    int i;
    HeapType* h;
    h = create();
    init(h);

    for(i = n-1; i>=0; i--) insert_max_heap(h, x[i]);
    for(i=0;i<n;i++) x[i]=delete_max_heap(h);
}

int main()
{
    int i;
    element list[6]={10,5,30,25,20,3};
    for_heap(list, 6);

    for(i=0; i<6; i++)
    {
        printf("%d ", list[i].key);
        if(i!=5) printf("-> ");
    }
}