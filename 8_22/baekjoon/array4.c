#include <stdio.h>
#include <string.h>

int main(){
    int N, M, i, j, k;
    char a[20];

    scanf("%d", &N);

    for(i = 0; i < N; i++){
        scanf("%d", &M);
        scanf("%s", a);
        for(j = 0; j < strlen(a); j++){
            for(k = 0; k < M; k++){
                printf("%c", a[j]);
            }
        }
        printf("\n");
    }

    return 0;
}