#include <stdio.h>

int Fibonacci(int num)
{
    int result;
    if(num==0) return 0;
    else if(num==1) return 1;
    else return Fibonacci(num-1)+Fibonacci(num-2); 
}

int main(){
    int num;
    scanf("%d", &num);
    printf("The result that Fibonacci of num\n ");
    for(int i = 0; i<=num; i++){
        printf("%d ", Fibonacci(i));
    }

    return 0;
}