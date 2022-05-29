#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *rootNode;
// Tree 초기화 -> rootNode만이 남는다.
void initTree(int data){
    rootNode = (Node*)malloc(sizeof(Node));
    rootNode->data=data;
    rootNode->left=NULL;
    rootNode->right=NULL;
}
// ChildNode 생성 -> Node이기 때문에, 반환값이 Node형.
Node *AddChild(Node *parent, int data){
    if((parent->left!=NULL)&&(parent->right!=NULL)){
        printf("The node is full!");
        return 0;
    }
    Node *new;
    new=(Node*)malloc(sizeof(Node));
    // new node의 초기값 설정
    new->data=data;
    new->left=NULL;
    new->right=NULL;
    if(parent->left==NULL) parent->left=new;
    else if(parent->right==NULL) parent->right=new;
    return new;
}
// 전위 순회(root->left->right)
void preorder(Node *r){
    printf("%d",r->data);
    if(r!=rootNode->right->right) printf("->");
    if(r->left) preorder(r->left);
    if(r->right) preorder(r->right);
}
// 중위 순회(left->root->right)
void inorder(Node *r){
    if(r->left) inorder(r->left);
    printf("%d", r->data);
    if(r!=rootNode->right->right) printf("->");
    if(r->right) inorder(r->right);
}
// 후위 순회(left->right->root)
void postorder(Node *r){
    if(r->left) postorder(r->left);
    if(r->right) postorder(r->right);
    printf("%d", r->data);
    if(r!=rootNode) printf("->");
}
int main(){
    Node *parent1;
    parent1=(Node*)malloc(sizeof(Node));
    Node *parent2;
    parent2=(Node*)malloc(sizeof(Node));
    initTree(1);
    parent1 = AddChild(rootNode, 2);
    AddChild(parent1,4);
    AddChild(parent1,5);
    parent2 = AddChild(rootNode, 3);
    AddChild(parent2, 6);
    AddChild(parent2, 7);
    rootNode->left=parent1;
    rootNode->right=parent2;
    printf("Preorder : ");
    preorder(rootNode);
    printf("\n");
    printf("Inorder : ");
    inorder(rootNode);
    printf("\n");
    printf("Postorder : ");
    postorder(rootNode);

}