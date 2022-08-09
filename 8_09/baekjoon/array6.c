#include <stdio.h>
#include <string.h>

int main(){
    int N, i, j, l = 0, num = 0, count = 0;
    char a[80];
    
    scanf("%d", &N);

    for(i = 0; i < N; i++){
        scanf("%s", a);
        
        l = strlen(a);

        for(j = 0; j < l; j++){
            if(a[j] == 'O'){
                num++;
                count += num;
            }

            if(a[j] == 'X'){
                num = 0;
            }
        }

        printf("%d\n", count);
        
        num = 0;
        count = 0;
    }
    
    return 0;
}