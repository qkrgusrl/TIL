#include <stdio.h>

int main(){
    int a[10], b[10], i, j, temp = 0, num = 10;

    for(i = 0; i < 10; i++){
        scanf("%d", &a[i]);
    }

    for(i = 0; i < 10; i++){
        b[i] = a[i] % 42;
    }

    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            if(b[i] < b[j]){
                temp = b[j];
                b[j] = b[i];
                b[i] = temp; 
            }
        }
    }
     
     for(i = 0; i < 10; i++){
        if(b[i] == b[i + 1]){
            num--;
        }
    }


    printf("%d\n", num);
    
    return 0;

}