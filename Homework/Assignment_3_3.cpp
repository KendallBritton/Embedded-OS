#include <stdio.h>

#define M 31 /* Mystery number 1 */
#define N 8  /* Mystery number 2 */

int arith(int x, int y){
    int result = 0;
    result = x*M + y/N; /* M and N are mystery numbers */
    return result;
}

int optarith(int x, int y){
    int t = x;
    x <<= 5;
    x -= t;
    if (y<0) y += 7;
    y >>= 3;    /* Arithmetic shift */
    return x+y;
}

int arith(int x, int y);
int optarith(int x, int y);

int main(){

    int ans;

    ans = arith(0, 0);
    printf("%d\n", ans);
    ans = optarith(0, 0);
    printf("%d\n", ans);


    return 0;
}