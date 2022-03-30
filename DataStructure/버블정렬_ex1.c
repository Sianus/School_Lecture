#include <stdio.h>

int main(void){
    int n[10] = {1, 10, 2, 3, 5, 6, 7, 9, 8, 4};
    int tmp;
    int count_compare = 0;
    int count_swap = 0;
    for(int i = 0; i<10; i++){
        for(int j = i+1; j<10; j++){
            count_compare++;
            if(n[i]<n[j]){
                tmp = n[j];
                n[j] = n[i];
                n[i] = tmp;
                count_swap++;
            }
        }
    }
    for(int i = 0; i<10; i++) printf("%d ",n[i]);
    printf("\n");
    printf("compare_count = %d\nswap_count = %d", count_compare, count_swap);
    return 0;
}