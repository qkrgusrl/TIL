#include <stdio.h>

int main(){
    int N, i;

    scanf("%d", &N);

    if(N > 100000){
        return 0;
    }

    for(i = 1; i <= N; N--){
        printf("%d\n", N);
        
    }

    return 0;
}