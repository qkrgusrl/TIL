#include <stdio.h>
#include <string.h>

int main(){
    int i, j, N = 0, num;
    char a[100];

    scanf("%s", a);

    N = strlen(a);

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(i == j){
                continue;
            }

            if(a[i] == a[j]){
                a[j] = 'A';
            }
        }
    }

    for(j = 97; j <= 122; j++){
        num = 0;
        for(i = 0; i < N; i++){
            if((int)a[i] == j){
                printf("%d ", i);
                num++;
            }
        }

        if(num == 0){
            printf("%d ", -1);
        }
    }

    printf("\n");

    return 0;
}