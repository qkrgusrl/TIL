#include <stdio.h>

int main(){
    int a, b;

    while(scanf("%d %d", &a, &b) != EOF){//이 문제는 더 이상 테스트 파일이 들어오지 않을때가 base case이다.

      if( a <= 0 || a >= 10){
         break;
      }

      if( b <= 0 || b >= 10){
         break;
      }

     printf("%d\n", a + b);

    }

    return 0;
}