#include <stdio.h>
int fun_a(unsigned x);

int main(){

unsigned int x = 0x0;
int ans = fun_a(x);
printf("%d\n",ans);

return 0;
}

int fun_a(unsigned x){
    int val = 0;
    while (x != 0){
        val = x ^ val;
        x = x >> 1;
    }
    return 0x1 & val;
}