#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Fibonacci_sequence(int a){

    if(a == 1 || a == 2){
        return 1;
    }

    else {
        return Fibonacci_sequence(a - 1) + Fibonacci_sequence(a - 2);
    }
}

int main(){
    int a, i, b = 0, c = 1, d = 0;

    scanf("%d", &a);

    printf("%d %d ", b, c);

    for(i = 0; i < a - 2; i++){
        d = b + c;
        b = c;
        c = d;
        printf("%d ", c);
    }

    printf("%d \n", Fibonacci_sequence(a));

    return 0;
}