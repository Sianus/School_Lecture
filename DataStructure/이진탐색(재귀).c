#include <stdio.h>
#define SWAP(x,y,z) ((z)=(x),(x)=(y),(y)=(z))
#define COMPARE(x,y) (x<y ? -1: (x==y ? 0:1))

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
int binsearch(int list[], int left, int right, int src)
{
    int mid;
    while(left<=right)
    {
        mid = (left+right)/2;
        switch(COMPARE(list[mid], src))
        {
            case -1 : return(binsearch(list, mid + 1, right, src));
                    break;
            case 0 : return mid;
            case 1 : return(binsearch(list, left, mid - 1, src));
        }
    }
    return -1;
}

int main(void)
{
    int list[] = {40, 50, 20, 80, 90, 10, 30};
    sort(list,7);
    int result = binsearch(list, 0, 7, 30);
    printf("%d", result);

    return 0;
}