#include <stdio.h>

int main(){
    int A, B, C, num, num2 = 0, i, a[10] = { 0, };

    scanf("%d %d %d", &A, &B, &C);

    num = A * B * C;

    for(i = 0; num > 0; i++){
        num2 = num % 10;
        a[num2]++;
        num /= 10;
    }

    for(i = 0; i < 10; i++){
        printf("%d\n", a[i]);
    }

    return 0;
}

//idea 1 10을 계속 나누게 된다면 나머지는 항상 맨뒷자리 한 자리가 나온다는 것!!
//idea 2 나오 나머지의 숫자만큼 그 배열의 크기 번째 수라고 생각하면 됨!!