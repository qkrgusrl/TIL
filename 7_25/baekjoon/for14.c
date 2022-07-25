#include <stdio.h>

int main(){
    int N, M = 0, a = 0, b = 0, c = 0, i = 0;

    scanf("%d", &N);
    M = N;

    while(1){
        a = M / 10;
        b = M % 10;

        c = a + b;
        
        M = 10*b + c % 10;

        i++;

        if(M == N){
            break;
        }
    }

    printf("%d\n", i);

    return 0;
}