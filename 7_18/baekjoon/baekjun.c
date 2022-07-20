#include <stdio.h>

int main(){
    int num1, num2, num3;

    scanf("%d %d %d", &num1, &num2, &num3);

    if( (num1 < 1 || num1 > 6) || (num2 < 1 || num2 > 6) || (num3 < 1 || num3 > 6)) {
        return 0;
    }

    if ( num1 == num2 && num2 == num3) {
        printf("%d\n", (10000 + num1*1000));
    }

    if(num1 == num2 && num2 != num3) {
        printf("%d\n", (1000 + num1*100));
    }

    if (num1 != num2 && num2 == num3) {
        printf("%d\n", (1000 + num2*100));
    }

    if (num1 == num3 && num1 != num2) {
        printf("%d\n", (1000 + num3*100));
    }

    if (num1 != num2 && num2 != num3 && num1 != num3){
        if(num1 > num2 && num1 > num3 && (num2 > num3 || num3 > num2)) {
            printf("%d\n", num1 * 100);
        }

        if(num2 > num3 && num2 > num1 && (num1 > num3 || num3 > num1)) {
            printf("%d\n", num2 * 100);
        }

        if(num3 > num1 && num3 > num2 && (num1 > num2 || num2 > num1)) {
            printf("%d\n", num3 * 100);
        }
    }

    return 0;
}