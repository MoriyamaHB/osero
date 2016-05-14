#ifndef __osero_mori
#define __osero_mori

//メイン
int mori_main(const int m[8][8],int bw,int* x,int *y);

//評価2
static double hyouka2(const int m1[8][8],const int m2[8][8], int bw, int x, int y);

//評価
static double hyouka(const int m1[8][8],const int m2[8][8], int bw, int x, int y);

#endif
