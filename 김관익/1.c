#include<stdio.h>
#define MAX_STACK_SIZE 100

typedef enum {
   lparen, rparen, plus, minus, times,
   divide, mod, eos, operand
} precedence;

char expr[10] = { '(','8', '*', '6',')', '+', '2', '/', '4' };

precedence stack[MAX_STACK_SIZE]; // The enum type values

/* isp and icp arrays -- Inlcude the value of precedence
lparen, rparen, plus, minus,times, divide, mode, eos */

static int isp[10] = { 0,19,12,12,13,13,13,0 };
static int icp[10] = { 20,19,12,12,13,13,13,0 };

void print_token(precedence val)
{
   switch (val) {
   case plus: printf("+"); break;
   case minus: printf("-"); break;
   case times: printf("*"); break;
   case divide: printf("/"); break;
   case mod: printf("%"); break;
   }
}

precedence pop(int* ptop) 
{
   return stack[(*ptop)--];
}

void push(int* ptop, precedence item) 
{
   stack[++*ptop] = item; 
}

precedence get_token(char* symbol, int* n) 
{
   *symbol = expr[*n];  
   (*n)++;

   switch (*symbol) {
   case '(': return lparen;
   case ')': return rparen;
   case '+': return plus;
   case '-': return minus;
   case '*': return times;
   case '/': return divide;
   case '%': return mod;
   case '\0': return eos;
   default: return operand;
   }
}

int eval(void) {
   precedence token;
   int op1, op2, n = 0, top = -1;
   char symbol;
   token = get_token(&symbol, &n); // precedence형 값
   while (token != eos) {  //토큰값이 빈칸이 아닐때까지 == 토큰값을 모두다 받아
      if (token == operand)  push(&top, symbol - '0'); // 토큰이 숫자면은 stack 에 넣어
      else  // 아니면 stack안에있는 값 2개를 뺴서 op2 op1에 각각 넣고 
         // 토큰 값에 따라 연산해서 push한다. stack에 넣는다 그러면 stack에는 숫자가 들어감 
      {   
         op2 = pop(&top); op1 = pop(&top);
         switch (token) {
         case plus: push(&top, op1 + op2); break;
         case minus: push(&top, op1 - op2); break;
         case times: push(&top, op1 * op2); break;
         case divide: push(&top, op1 / op2); break;
         case mod: push(&top, op1 % op2);
         }
      }
      token = get_token(&symbol, &n); // 다시 토큰 값을 받는다.
   }  // while 
   return pop(&top);   // 그리고 제일 위에 있는 값을 빼서 print한다.
}

void itop(void) 
{
   // e는 주어진 중위표기식으로 끝은 ;으로 표시 
   // ISP와 ICP는 우선 순위를 반환해주는 함수 
   // pos는 e에서 현재 위치  
   char symbol; 
   precedence token;
   int n = 0, top = 0;
   stack[top] = eos;
   for (token = get_token(&symbol, &n); token != eos;
      token = get_token(&symbol, &n)) //토큰이 eos일때 까지 돌린다.
   {
      if (token == operand)   
         printf("%c", symbol);
      else if (token == rparen) {
         while (stack[top] != lparen)
            print_token(pop(&top));            
         pop(&top);  // 왼쪽괄호를 버림
      }
      else {
         while (isp[stack[top]] >= icp[token]) {
            print_token(pop(&top));
         }
         push(&top, token);
      }  // else 
   }  // for
   while ((token = pop(&top)) != eos)
      print_token(token);   
   printf("\n");
}

int main()
{
   itop();
}