#include <stdio.h>
#include <string.h>

int main(){
    int N, i, j, l = 0, num = 0, count = 0;
    char a[80];
    
    scanf("%d", &N);

    for(i = 0; i < N; i++){
        scanf("%s", a[80]);
        
        l = strlen(a);

        for(j = 0; j < l; l++){
            if(a[l] == 'O'){
                num++;
            }

            if(a[l] == 'X'){
                num = 0;
            }

            count += num;
        }

        printf("%d\n", count);
    }
    
    return 0;
}