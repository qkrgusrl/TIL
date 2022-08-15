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
    int a[3], j = 0, num = 0;

    while(i > 0){
       num = i % 10;
       i /= 10;
       a[j] = num;
       j++;
    }

    if(a[0] - a[1] == a[1] - a[2]){
        return 1;
    }

    else{
        return 0;
    }

}

int phg3(int i){
    int a[4], j = 0, num = 0;
    while(i > 0){
       num = i % 10;
       i /= 10;
       a[j] = num;
       j++;
    }

    if((a[0] - a[1] == a[1] - a[2]) && (a[1] - a[2] == a[2] - a[3])){
       return 1;
    }

    else{
        return 0;
    }

}

int main(){
    int N, i, num = 0;

    scanf("%d", &N);

    for(i = 1; i <= N; i++){
        if(phg1(i) <= 2){
            num++;
        }

        else if(phg1(i) == 3){
            if(phg2(i) == 1){
                num++;
            }
        }

        else if(phg1(i) == 4){
            if(phg3(i) == 1){
                num++;
            }
        }
    }

    printf("%d\n", num);

    return 0;
}