#include <stdio.h>

int main(void)
{
    int a[2][2] = {{1,2}, {2,3}};
    int b[2][2] = {{3,4},{4,5}};
    int result[2][2];
    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            result[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j];
        }
    }
    for(int i = 0; i<2; i++){
        for(int j =0; j<2; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}