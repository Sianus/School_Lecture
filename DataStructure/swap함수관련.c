#include <stdio.h>

int main(){
    int a, b;
    int *x, *y;
    a = 1;
    b = 2;
    x = &a;
    y = &b;
    printf("%d %d %d %d\n",a,b, x, y);
    int *tmp;
    *tmp = *x;
    *x = *y;
    *y = *tmp;
    printf("%d %d %d %d",a,b, x, y); 

    return 0;
}