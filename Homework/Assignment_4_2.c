#include <stdio.h>



//void decode1(int *xp, int *yp, int *zp);

//int main(){

    //int xp, yp, zp;



    //xp = 2;
    //yp = 6;
    //zp = 8;

    //decode1(&xp, &yp, &zp);


  //  return 0;
//}

void decode1(int *xp, int *yp, int *zp){

    int x = *xp;
    int y = *yp;
    int z = *zp;

    *yp = x;
    *zp = y;
    *zp = z;

}