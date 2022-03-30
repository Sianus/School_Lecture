#include <stdio.h>

int main()
{
    int i, *pi;
    float f, *pf;
    pi = (int *) malloc(sizeof(int));
    pf = (float*) malloc(sizeof(float));
    *pi = 1024;
    *pf = 3.14;
    printf("an integer = %d, a float = %f\n %d %d", *pi, *pf, i, f);
    free(pi);
    free(pf);

    return 0;
}
/*
< Pointer >
& : 주소 연산자
* : 간접 지시 연산자
    *pi = &a;
    a = 10;(=*pi = 10 | 포인터 pi가 가리키는 장소에 10을 저장하라는 뜻)
*/