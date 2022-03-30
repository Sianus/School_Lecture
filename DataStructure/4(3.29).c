#include <stdio.h>
#define SWAP(x,y,z) ((z)=(x),(x)=(y),(y)=(z))

void sort(int list[], int n)
{
    int i, j, min, temp;
    for(i = 0; i<n-1; i++){
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(list[j]<list[min]) min=j;
        }
        SWAP(list[i],list[min], temp);
    }
}

int binsearch(int list[], int size, int searchnum)
{
    int left, right;
    left = 0;
    right = size -1;
    int mid;
    while(left<=right){
        mid = (left+right)/2;
        if(searchnum == list[mid]) return mid;
        else if(searchnum < list[mid]) right = mid-1;
        else left = mid + 1;
    }
    return -1;
}

int main(void)
{
    int list[] = {40, 50, 20, 80, 90, 10, 30};
    sort(list,7);
    int result = binsearch(list, 7, 30);
    printf("%d", result);

    return 0;
}