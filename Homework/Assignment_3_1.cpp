#include <stdio.h>
#include <stdint.h>


int tadd_ok(int x, int y);

int tadd_ok(int x, int y){      // Note that int is 32 bits
    
    int sum = x + y;

    if (((x > 0) && (y > 0)) && (sum <= 0)){

        printf("Positive Overflow\n");
        return -1;

    } else if (((x < 0) && (y < 0)) && (sum >= 0)){
        
        printf("Negative Overflow\n");
        return -1;

    } else {

        printf("No Overflow\n");
        return 1;
    }

}


int main()
{

    tadd_ok(2147483640, 245);
    printf("\n");

    tadd_ok(50000, 35000);
    printf("\n");

    tadd_ok(-2147483640, -245);

    return 0;
}