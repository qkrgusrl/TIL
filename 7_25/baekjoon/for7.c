#include <stdio.h>

int main(){
    int T, a, b, i;

    scanf("%d", &T);

    for(i = 1; i <= T; i++){
        scanf("%d %d", &a, &b);

        if (a < 0 || b >= 10){
            break;
        }
        

        printf("Case #%d: ", i);
        printf("%d\n", a + b);
    }

    return 0;
}