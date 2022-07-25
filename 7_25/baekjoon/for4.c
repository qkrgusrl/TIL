#include <stdio.h>

int main(){
    int T, a, b, i;

    scanf("%d", &T);

    if(T > 1000000){
        return 0;
    }

    for(i = 0; i < T; i++){

        scanf("%d %d", &a, &b);

        if(a < 1 || a > 1000){
            break;
        }

         if(a < 1 || a > 1000){
            break;
        }

        printf("%d\n", a + b);
    }

    return 0;
}