#include <stdio.h>

int main(){
    int X, N, A, i;

    scanf("%d %d", &N, &X);

    for(i = 0; i < N; i++){
        scanf("%d", &A);
        if(X > A){
            printf("%d ", A);
        }
    }

    return 0;
}