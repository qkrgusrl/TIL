#include <stdio.h>

int main(){
    int i, j, k, N, M;

    scanf("%d", &N);

    M = N;

    if(N < 1||N > 100){
        return 0;
    }

    for(i = 0; i < N; i++){

        for(k = 0; k < M - 1; k++){
            printf(" ");
        }

        for(j = 0; j <= i; j++){
            printf("*");
        }

        printf("\n");
        M--;
    }
}