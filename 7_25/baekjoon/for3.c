#include <stdio.h>

int main(){
    int N, i, sum = 0;

    scanf("%d", &N);

    if(N < 0 || N > 10000){
        return 0;
    }

    for (i = 0; i <= N; i++){
        sum += i;
    }

    printf("%d\n", sum);

    return 0;
}