#include <stdio.h>

int main(){
    int a[1000], N, i, max = 0;
    double arv = 0.0;

    scanf("%d", &N);

    for(i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }

    for(i = 0; i < N; i++){
        if(max < a[i]){
            max = a[i];
        }
    }

    for(i = 0; i < N; i++){
        arv += (double)a[i]/(double)max*100;
    }

    arv /= N;

    printf("%lf", arv);
}