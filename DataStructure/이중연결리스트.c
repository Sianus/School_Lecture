#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct dnode {
	element data;
	struct dnode *llink;
	struct dnode *rlink;
} node1;
typedef node1 * nodePointer;

int cnt=0;

void dinsert(nodePointer node, nodePointer newnode, int index) {
    if (cnt==0) {
        newnode ->llink = node;
        newnode -> rlink = node -> rlink;
        node -> rlink -> llink = newnode;
        node -> rlink = newnode;
        cnt++;
        return;
    }
    nodePointer temp=node;
    // while (temp->rlink!=node) temp=temp->rlink;
    int i;
    for(i=1;i<index;i++) temp=temp->rlink;
    newnode ->llink = temp;
    newnode -> rlink = temp -> rlink;
    temp -> rlink -> llink = newnode;
    temp -> rlink = newnode;
    cnt++;
}
void ddelete(nodePointer node, nodePointer deleted) {
    deleted -> llink ->rlink = deleted -> rlink;
    deleted -> rlink -> llink = deleted -> llink;
    free(deleted);
    cnt--;
}
void dinsertback(nodePointer head, int searchnum, int data) {
    int index=1;
    nodePointer temp=head->rlink;

    while (temp->data!=searchnum && temp!=head) {
        temp=temp->rlink;
        index++;
    }
    nodePointer newnode=(nodePointer)malloc(sizeof(node1));
    newnode->data=data;
    dinsert(head, newnode, index+1);
}
void printlist(nodePointer head) {
    nodePointer temp=head->rlink;
    while (1) {
        printf("%d", temp->data);
        temp=temp->rlink;
        if (temp==head) break;
        printf(" -> ");
    }
    printf("\n");
}
int main(void) {
    nodePointer head=(nodePointer)malloc(sizeof(node1));
    head->llink=head; head->rlink=head;
    nodePointer temp;
    int i;
    for(i=2;i<=20;i+=2) {
        temp=(nodePointer)malloc(sizeof(node1));
        temp->data=i;
        dinsert(head, temp, cnt+1);
    } printlist(head);
    temp=(nodePointer)malloc(sizeof(nodePointer));
    temp->data=1; dinsert(head, temp, 1); printlist(head);
    temp=(nodePointer)malloc(sizeof(nodePointer));
    temp->data=21;
    dinsert(head, temp, cnt+1);
    printlist(head);
    dinsertback(head, 18, 11);
    printlist(head);
    
    // int delnum=21; temp=head->rlink; while (temp->data!=delnum) temp=temp->rlink;
    // ddelete(head, temp); printlist(head);
}