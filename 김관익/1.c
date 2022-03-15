#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y);
int main()
{
    int n;
    scanf("%d", &n);
    int *list = (int *)malloc(sizeof(4*n));
    for(int i =0; i<n; i++){
        scanf("%d", &list[i]);
    }
    int min;
    int cnt;
    for(int i = 0;i<n;i++){
        min = list[i];
        cnt = i;
        for(int j = i+1; j <n; j++){
            if (list[j]<min){
                min = list[j];
                cnt = j;
            }
        }
        swap(&list[i], &list[cnt]);
    }
    
    for(int i = 0;i<n;i++) printf("%d ", list[i]);
    printf("\n");

    //binaty search

    int x;
    scanf("%d", &x);

    int l , r , m;
    l=0; r=n; m=(l+r)/2;

    while(1){
        if(l>r) {
            printf("Not founded");
            break;
        }


        if(x == list[m]){
            printf("%d", x);
            break;
        }
        else if (x>list[m]){
            l = m+1;
            m=(l+r)/2;
        }
        else{
            r = m-1;
            m=(l+r)/2;
        }
    }

    return 0;
}

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}