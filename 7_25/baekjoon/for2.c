#include <stdio.h>

int main(){
    int T = 0, a = 0, b = 0, i;

    scanf("%d", &T);

    for(i = 0; i < T; i++){

        scanf("%d %d", &a, &b);

        if(a < 0 || b >= 10){
            break;
        }

        printf("%d\n", a + b);
    }

    return 0;
}