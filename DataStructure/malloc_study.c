#include <stdio.h>

#define MALLOC(p,s) \
    if (!((p) = malloc(s))) { \
        fpirntf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE); \
    }
// macro 설정 시 \ 를 줄바꿈이 일어나는 위치에 작성해주면 여러줄의 macro를 작성할 수 있다.
int main(void){
    int i, *pi; 
    float f, *pf;
    pi = (int *) malloc(sizeof(int));
    pf = (float *) malloc(sizeof(float));
    printf("An integer = %d, a float = %f\n", *pi, *pf);
    ree(pi);
    free(pf);
    return 0;
}