#include <stdio.h>
#include <string.h>

int main(){
    int i, j, max = 0, num = 0, k = 0;
    char a[1000], b, c[26];

    scanf("%s", a);

    for(i = 0; i < strlen(a); i++){
        if((int)a[i] >= 65 && (int)a[i] <= 90){
            a[i] = (int)a[i] + 32;
        }
    }

    for(i = 97; i <= 122; i++){
        num = 0;
        for(j = 0; j < strlen(a); j++){
            if((int)a[j] == i){
                num++;
            }
        }

        if(max < num){
           max = num;
           b = i;
        }
    }

     printf("%c\n", b - 32);

    return 0;
}