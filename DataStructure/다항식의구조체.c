#include <stdio.h>

#define MAX_TERMS 100
#define COMPARE(x,y) (x<y ? -1: (x==y ? 0:1))

typedef struct{
    float coef; //다항식 계수
    int expo; // 다항식 지수
} poly; // 다항식

poly terms[MAX_TERMS]; // 결과항을 저장하기 위한 배열
int avail=0; // 작업할 위치

void attach(float coef, int expo) //항을 만들어주는 함수
{
    if(avail >= MAX_TERMS)
    {
        printf("Too many poly\n");
        exit(1);
    }

    terms[avail].coef = coef;
    terms[avail].expo = expo;
    avail++;
}

void padd(int start_a, int finish_a, int start_b, int finish_b, int *start_d, int *finish_d)
{
    float coeff;
    *start_d = avail; // 결과값의 시작점   

    while (start_a <= finish_a && start_b <= finish_b)
    {
        switch(COMPARE(terms[start_a].expo, terms[start_b].expo))
        {
            case -1: //start_a < start_b
                attach(terms[start_b].coef, terms[start_b].expo);
                start_b++; // b 다음 항으로 넘김
                break;
            case 0: // start_a == start_b
                coeff = terms[start_a].coef + terms[start_b].coef;
                attach(coeff, terms[start_a].expo);
                start_a++;
                start_b++;
                break;
            case 1: // start_a > start_b
                attach(terms[start_a].coef, terms[start_a].expo);
                start_a++; // a 다음 항으로 넘김
        }
    }

    for(;start_a <= finish_a; start_a++) attach(terms[start_a].coef, terms[start_a].expo);
    for(;start_b <= finish_b; start_b++) attach(terms[start_b].coef, terms[start_b].expo); 
    *finish_d = avail - 1; // attach에서 마지막에 avail++ 이 한 번 더 되기 때문에 -1 해줌.
}

int main()
{
    int start_a = 0, start_b, start_d, finish_a = 0, finish_b, finish_d;
    float coef;
    int expo;
    do
    {
        printf("The first poly coef : ");
        scanf("%f", &coef);
        printf("The first poly expo : ");
        scanf("%d", &expo);
        attach(coef, expo);
        finish_a++;
    } while(expo != 0);
    start_b = finish_a;
    finish_b = start_b;
    do
    {
        printf("The second poly coef : ");
        scanf("%f", &coef);
        printf("The second poly expo : ");
        scanf("%d", &expo);
        attach(coef, expo);
        finish_b++;
    } while(expo != 0);
    
    padd(start_a, finish_a-1, start_b, finish_b-1, &start_d, &finish_d);
    for(int i = start_d; i<=finish_d; i++)
    {
        if(i != finish_d) printf("%.2f X^ %d + ", terms[i].coef, terms[i].expo);
        else printf("%.2f", terms[i].coef);
    }    
    return 0;
}