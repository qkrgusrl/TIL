#include <stdio.h>

int phg(int i){
    int num = i;

    while(i > 0){
        num += i % 10;
        i /= 10;
    }

    return num;
}

int main(){
   
    int i, j = 0, num, a[10000] = {0}, temp = 0;

    for(i = 1; i <= 10000; i++){
        a[j] = phg(i);
        j++;
    }

    for(i = 0; i < 10000; i++){
        for(j = 0; j < 10000; j++){
            if(a[i] < a[j]){
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }

    for(i = 1; i <= 10000; i++){
        num = 0;
        for(j = 0; j < 10000; j++){
            if(a[j] == i){
                num++;
            }
        }

        if(num == 0){
            printf("%d\n", i);
        }
    }

    return 0;
}