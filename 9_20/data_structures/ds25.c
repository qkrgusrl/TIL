#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int phg(int a){
    while(a > 1){
       return a + phg(a - 1);
    }
}

int main(){
    int a;

    scanf("%d", &a);

    printf("%d\n", phg(a));

    return 0;
}