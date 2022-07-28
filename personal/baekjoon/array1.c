#include <stdio.h>

int main(){
    int N, i, max, min, a[100001];

    scanf("%d", &N);

    for(i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }

    min = a[0];
    max = a[0];

    for(i = 0; i < N; i++){
        if(a[i] > max){
            max = a[i];
        }

        if(a[i] < min){
            min = a[i];
        }
    }

    printf("%d %d\n", min, max);

    return 0;
}