#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*struct A{ //구조체 정의 
    int a; //member 1
    int b; //member 2
};

struct B{
    struct A a;
    int b;
};

struct C{
    struct B b;
    struct A a;
    int c;
};

main()
{
    struct A a; //구조체 A형 변수 a선언
    a.a = 10; 
    a.b = 20;
    printf("a.a = %d\na.b = %d\n",a.a,a.b);

    struct C c;
    c.b.a.a = 10;
    c.b.a.b = 20;
    c.a.a = 15;
    c.a.b = 25;
    c.b.b = 30;
    c.c = 35;

    printf("c.b.a.a = %d\nc.b.a.b = %d\nc.a.a = %d\nc.a.b = %d\nc.b.b =%d\nc.c = %d\n",c.b.a.a ,c.b.a.b,c.a.a,c.a.b,c.b.b,c.c);
    return 0;
}*/

struct namec{
    int a;
    char a_str[20];
};

struct namecard2{
    int b;
    char b_str[20];
    
}
