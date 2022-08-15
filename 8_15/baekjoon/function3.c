#include <stdio.h>

int phg1(int i){

    int num = 0;

    while(i > 0){
        i /= 10;
        num++;
    }

    return num;
}

int phg2(int i){

}

int main(){
    int N, i, num = 0;

    scanf("%d", &N);

    for(i = 1; i <= N; i++){
        if(phg1(i) <= 2){
            num++;
        }

        else if(phg1(i) == 3){
            phg2(i);
        }

        else if(phg1(i) == 4){
            phg3(i);
        }
    }

    printf("%d", num);

    return 0;
}