#include <stdio.h>

// int main(){
    // int num1, num2, *p = &num1;
    // *p = 3000;
    // num2 = *p;
    // p = &num2;
    // *p = *p - 1000;
    // num1 = 2 * *p;

    // printf("%d %d %p\n", num1, num2, p);
    // printf("%p %p %p\n", &num1, &num2, &p);

    // return 0;
// }

// void swap(int *a, int *b){

    // int temp = 0;

    // temp = *a;
    // *a = *b;
    // *b = temp;

// }

// int main(){
    // int a = 10, b = 20;

    // swap(&a, &b);

    // printf("%d %d\n", a, b);

    // return 0;
// }

//배열과 포인터의 차이점 찾기

struct student {
    int id;
    char name[100];
    double grade;
};

void init_p(struct student *pst){
    struct student st2 = {20, "Mom", 3.5};
    *pst = st2;
}

int main(){
    struct student st1 = {10, "Tom", 3.2};
    init_p(&st1);
    printf("%d, %s, %.2f\n", st1.id, st1.name, st1.grade);

    return 0;
}