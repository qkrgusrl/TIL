#include <stdio.h>

int main(){
    int a[9], i, max, num = 0;

    for(i = 0; i < 9; i++){
        scanf("%d", &a[i]);
    }

    for(i = 0; i < 9; i++){
        if(a[i] >= 100 || a[i] <= 0){
            return 0;
        }
    }

    max = a[0];

    for(i = 0; i < 9; i++){
        if(a[i] >= max){
            max = a[i];
            num = i + 1;
        }
    }

    printf("%d\n", max);
    printf("%d\n", num);

    return 0;
}