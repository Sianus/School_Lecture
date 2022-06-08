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

HeapType heap1;

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

void show_max_heap(HeapType *h) {
    int i;
    for(i=1;i<h->heap_size;i++) printf("%d -> ", h->heap[i]);
    printf("%d\n", h->heap[i]);
}
int main(void) {
    HeapType *heap1=create(); init(&heap1);
    element item;
    item.key=10; insert_max_heap(&heap1, item);
    item.key=5; insert_max_heap(&heap1, item);
    item.key=30; insert_max_heap(&heap1, item);
    item.key=25; insert_max_heap(&heap1, item);
    item.key=20; insert_max_heap(&heap1, item);
    item.key=3; insert_max_heap(&heap1, item);
    show_max_heap(&heap1);
}