#include <stdio.h>

#define MAX_TERMS 100
#define MAX_COL 100


typedef struct {
    int row;
    int col;
    int val;
} term;

term a[MAX_TERMS], nom[MAX_TERMS], fast[MAX_TERMS];

void transpose(term a[], term b[]){

    int n, i, j, currentb;

    n = a[0].val;

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = n;

    if(n>0){
        currentb = 1;
        for(i=0; i<a[0].col; i++){
            for(j=1;j<=n; j++){
                if(a[j].col == i){
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].val = a[j].val;
                    currentb++;
                }
            }
        }
    }
}

void fastTranspose(term a[], term b[]){

    int row_terms[MAX_COL], starting_pos[MAX_COL], num_cols, num_terms, i, j;

    b[0].row = num_cols = a[0].col;
    b[0].col = a[0].row;
    b[0].val = num_terms = a[0].val;

    if(num_terms > 0){
        for(i = 0; i < num_cols; i++) row_terms[i] = 0;
        for(i = 1; i<= num_terms; i++) row_terms[a[i].col]++;
        starting_pos[0] = 1;

        for(i=1; i< num_cols; i++) starting_pos[i]=starting_pos[i-1] + row_terms[i-1];

        for(i = 1; i< num_terms; i++){
            j = starting_pos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].val = a[i].val;
        }
    }


}


void print_Mat(term a[], int size){
    for(int i =0; i<size; i++) printf("%d %d %d\n", a[i].row, a[i].col, a[i].val);
}

int main(){
    for(int i = 0; i<9; i++) scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].val);
    printf("< Matrix a >\n");
    print_Mat(a,9);
    transpose(a, nom);
    fastTranspose(a,fast);
    printf("< Show TransPose result >\n");
    print_Mat(nom,9);
    printf("< Show FastTranspose result >\n");
    print_Mat(fast, 9);

    return 0;
}