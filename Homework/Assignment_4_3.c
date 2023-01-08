// #include <stdio.h>
// //#include <bits/libc-header-start.h>

// int decode2(int x, int y, int z);

// int main(){

//     decode2(12, 63, 200);

//     return 0;
// }

int decode2(int x, int y, int z){

    int ans1, ans2; // ans1 = %edx, ans2 = %eax

    ans1 = y;
    ans1 = ans1 - z;
    ans2 = ans1;
    ans2 = ans2 << 31;
    ans2 = ans2 >> 31;
    ans1 = ans1 * x;
    ans2 = ans2 ^ ans1;
    return ans2;
    // printf("Edx: %d\n", ans1);
    // printf("Eax: %d\n", ans2);
}