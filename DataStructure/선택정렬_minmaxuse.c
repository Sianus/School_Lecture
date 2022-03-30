#include <stdio.h>

#define SWAP(x,y,z) ((z)=(x),(x)=(y),(y)=(z))

void sort(int list[], int n){
    int i, j, max, temp;
    int compare_count = 0;
    int swap_count = 0;
    for(i=0; i<n-1; i++){
        max=i;
        for(j=i+1;j<n;j++){
            compare_count++;
            if(list[j]>list[max]) max=j;
        }
        SWAP(list[i],list[max],temp);
        swap_count++;
        
    }
    for(i = 0; i<10; i++) printf("%d ", list[i]);
    printf("\n");
    printf("compare_count = %d\nswap_count = %d", compare_count, swap_count);
}

int main(void){
    int n[10] = {1, 10, 2, 3, 5, 6, 7 ,9, 8, 4};
    sort(n,10);
    return 0;
}