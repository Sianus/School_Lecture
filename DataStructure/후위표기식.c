#include <stdio.h>
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100
typedef enum{
    lparen, rparen, plus, minus, times, divide, mod, eos, operand
} precedence;

char expr[]="(3*2)-1/3;";
char post_expr[MAX_EXPR_SIZE]="";
int index=0;

precedence stack[MAX_STACK_SIZE];

static int isp[10] = { 0,19,12,12,13,13,13,0 }; // stack 넣을 때 우선 순위
static int icp[10] = { 20,19,12,12,13,13,13,0 }; // stack 안에 있을 때 우선 순위

precedence pop(int* ptop)
{
    return stack[(*ptop)--];
}
precedence push(int* ptop, precedence item)
{
    stack[++(*ptop)]=item;
}

precedence get_token(char *symbol, int *n, char *string){
    *symbol=string[*n]; // 중위 표기식에서 값 받아오는 코드
    (*n)++;
    switch(*symbol){ // symbol 값에 따른 반환값 지정
        case '(': return lparen;
        case ')': return rparen;
        case '+' : return plus;
        case '-' : return minus;
        case '*' : return times;
        case '/' : return divide;
        case '%' : return mod; 
        case ';' : return eos;
        default : return operand;
    }
}

void input_token(precedence val){
    switch (val)
    {
        case plus: post_expr[index++]='+'; break;
        case minus: post_expr[index++]='-'; break;
        case times: post_expr[index++]='*'; break;
        case divide: post_expr[index++]='/'; break;
        case mod: post_expr[index++]='%'; break;
        case eos: post_expr[index++]=';'; break;
        default : post_expr[index++]="";
    }
}

int eval(void){
    precedence token;
    int op1, op2, n=0, top=-1;
    char symbol;
    token=get_token(&symbol, &n, post_expr);
    while(token != eos){
        if(token == operand) push(&top, symbol-'0'); // symbol-'0'은 int형으로 변환하는 방법
        else{
            op2 = pop(&top); op1 = pop(&top);
            
            switch(token){
                case plus: push(&top, op1+op2); break;
                case minus: push(&top, op1-op2); break;
                case times: push(&top, op1*op2); break;
                case divide: push(&top, op1/op2); break;
                case mod: push(&top, op1%op2);
            } // switch
        } // else
        token = get_token(&symbol, &n, post_expr);
    } // while
    return pop(&top);
}

void postfix(void){
    char symbol;
    precedence token;
    int n=0, top=0;
    stack[top]=eos;
    for(token=get_token(&symbol,&n, expr); token != eos;
      token=get_token(&symbol, &n, expr)){
        if(token==operand) post_expr[index++]=symbol;
        else if(token==rparen){
            while(stack[top]!=lparen) input_token(pop(&top));
            pop(&top);
        } // else if
        else{
            while(isp[stack[top]] >= icp[token]) input_token(pop(&top));
            push(&top, token); 
        } // else
    } // for
    while((token=pop(&top))!=eos) input_token(token);
    input_token(eos);
}

int main(){
    int i;
    printf("Infix : ");
    for(i=0;expr[i]!=';';i++) printf("%c", expr[i]);
    postfix();
    printf("\nPostfix : ");
    for(i=0;post_expr[i]!=';';i++) printf("%c", post_expr[i]);
    int result=eval();
    printf("\nResult : %d", result);
}