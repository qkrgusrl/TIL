#include <stdio.h>

int main(){
    int a[1000], N, i, j, num = 0, count = 0;
    float avr;

    scanf("%d ", &N);
    
    for(i = 0; i < N; i++){
        scanf("%d", &a[0]);

        for(j = 1; j <= a[0]; j++){
            scanf("%d", &a[j]);
            num += a[j];
        }

        avr = (float)num / (float)a[0];

        for(j = 1; j <= a[0]; j++){
            if(a[j] > avr){
                count++;
            }
        }

        printf("%.3f%%\n", (float)count*100 / (float)a[0]);

        count = 0;
        num = 0;
    }

    return 0;
}