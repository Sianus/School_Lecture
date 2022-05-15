#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100
typedef enum {lparen, rparen, plus, minus, times, divide, mod, eos, operand} precedence;
int stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE]="(3*2)-1/3;"; char post_expr[MAX_EXPR_SIZE]="";

void push(int *top, int num) {
    stack[++(*top)]=num;
}

int pop(int *top) {
    return stack[(*top)--];
}
//lparen, rparen, plus, minus, times, divide, mod, eos
static int isp[] = {0, 19, 12, 12, 13, 13, 13, 0}; // in-stack
static int icp[] = {20, 19, 12, 12, 13, 13, 13, 0}; // incoming

precedence getToken(char *symbol, int *n, char *s) {
    *symbol=s[*n];
    (*n)++;
    switch (*symbol) {
        case '(': return lparen;
        case ')': return rparen;
        case '+': return plus;
        case '-': return minus;
        case '*': return times;
        case '/': return divide;
        case '%': return mod;
        case ';': return eos;
        default: return operand;
    }
}

char putToken(int n)
{
    switch(n)
    {
    case minus:     return '-';
    case lparen:    return '(';
    case rparen:    return ')';
    case plus:     return '+';
    case divide:    return '/';
    case times:     return '*';
    case mod:     return '%';
    case eos:     return ';';
    default : return "";
    }
}
int postindex=0;

void printToken(int n) {
   post_expr[postindex++]=putToken(n);
}

int eval(void) {
    precedence token;
    int op1, op2, n=0, top=-1;
    char symbol;
    token=getToken(&symbol, &n, post_expr);
    while (token!=eos) {
        if (token==operand) push(&top, symbol-'0');
        else {
            op2=pop(&top); op1=pop(&top);
            switch (token) {
                case plus: push(&top, op1+op2); break;
                case minus: push(&top, op1-op2); break;
                case times: push(&top, op1*op2); break;
                case divide: push(&top, op1/op2); break;
                case mod: push(&top, op1%op2);
            }
        }
        token=getToken(&symbol, &n, post_expr);
    }
    return pop(&top);
}

void postfix(void) {
    char symbol;
    precedence token;
    int n=0;
    int top=0;
    stack[0]=eos;
    for(token=getToken(&symbol, &n, expr); token!=eos;token=getToken(&symbol, &n, expr)) {
        if (token==operand) post_expr[postindex++]=symbol;
        else if (token==rparen) {
            while (stack[top]!=lparen) printToken(pop(&top));
            pop(&top);
        }
        else {
            while (isp[stack[top]]>=icp[token]) printToken(pop(&top));
            push(&top, token);
        }
    }
    while((token=pop(&top))!=eos) printToken(token);
    //printToken(';');
}

int main(void) {
    int i;
    printf("중위계산식 : ");
    for(i=0;expr[i]!=';';i++) printf("%c", expr[i]);
    postfix();
    post_expr[postindex]=';';
    printf("\n후위계산식 : ");
    for(i=0;post_expr[i]!=';';i++) printf("%c", post_expr[i]);
    int result=eval();
    printf("\n결과 : %d", result);
}