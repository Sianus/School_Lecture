#include <stdio.h>

int main(void)
{
    int a[3][3] = {{1,3,4},{5,6,7},{3,2,1}};
    int b[3][3] = {{2,4,5},{3,6,7},{4,3,2}};
    int res[3][3];
    for(int row = 0; row<3; row++){
        for(int col = 0; col<3; col++)
        {
            int sum = 0;
            for(int n = 0; n<3; n++) sum = sum + a[row][n]*b[n][col];
            res[row][col] = sum;
        }
    }
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++) printf("%d ", res[i][j]);
        printf("\n");
    }
}