#include <stdio.h>

int main(){

    int i, N = 0, num = 0;
    char a[100];

    scanf("%d", &N);
    scanf("%s", a);

    for(i = 0; i < N; i++){
        if((int)a[i] < 52){
           num += a[i] % 6;  
        }

        if((int)a[i] >= 52) {
            num += (a[i] % 10) + 2;
        }

    }

    printf("%d\n", num);

    return 0;
}