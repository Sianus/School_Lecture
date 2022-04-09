#include <stdio.h>
#include <string.h>

void strins (char *s, char *t, int i){
    char temp[100];
    if(i<0 || i>strlen(s)){
        printf("Error!");
        exit(1);
    }
    if(!strlen(s)) strcpy(s,t);
    else if(strlen(t)){
        strncpy(temp, s, i);
        strcat(temp, t);
        strcat(temp, s+i);
        strcpy(s, temp);
    }
}

int main(){
    char s[] = "superputer";
    char t[] = "com";
    printf("s = %s\n", s);
    printf("t = %s\n", t);
    strins(s, t, 5);
    printf("strnins s = %s", s);
}