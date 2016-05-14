#include<stdio.h>
#include"osero.h"
#include"osero_mori.h"

//マスの重み
int h[8][8] = {
	{ 45, 3, 15, 14, 14, 15, 3, 45 },
	{ 3, 0, 12, 12, 12, 12, 0, 3 },
	{ 15, 12, 15, 14, 14, 15, 12, 15 },
	{ 14, 12, 14, 14, 14, 14, 12, 14 },
	{ 14, 12, 14, 14, 14, 14, 12, 14 },
	{ 15, 12, 15, 14, 14, 15, 12, 15 },
	{ 3, 0, 12, 12, 12, 12, 0, 3 },
	{ 45, 3, 15, 14, 14, 15, 3, 45 }
};

//メイン
int mori_main(const int m[8][8],int bw, int* x, int *y){
	int temp[8][8];
	int tx, ty;
	int i, j;
	double max = -1, max_temp;

	for (i = 0; i < 8; i++){
		for (j = 0; j < 8; j++){
			if (m[i][j] == 0){
				copy(m, temp);
				convert_osero(temp, bw, i, j);

				if (bw == 1)
					max_temp = hyouka(m, temp, bw, i, j);
				else
					max_temp = hyouka2(m, temp, bw, i, j);

				if (max < max_temp){
					max = max_temp;
					tx = i;
					ty = j;
				}
			}
		}
	}


	if (max <= 0){
		return -1;
	}
	else{
		*x = tx;
		*y = ty;
		return 0;
	}
}

//評価
static double hyouka(const int m1[8][8],const int m2[8][8], int bw, int x, int y){
	int t1, t2;
	double tensu;
	//取れる枚数から計算
	t1 = calc_bw(m1, bw);
	t2 = calc_bw(m2, bw) - 1;
	if (t2 - t1 <= 0)//一枚も取れないなら
		return 0;//0を返す
	else
		tensu = t2 - t1;

	//場所点数加算
	tensu += h[x][y] * 1;

	return tensu;
}

//評価2
static double hyouka2(const int m1[8][8],const int m2[8][8], int bw, int x, int y){
	int t1, t2;
	double tensu;
	//取れる枚数から計算
	t1 = calc_bw(m1, bw);
	t2 = calc_bw(m2, bw) - 1;
	if (t2 - t1 <= 0)//一枚も取れないなら
		return 0;//0を返す
	else
		tensu = t2 - t1;

	//場所点数加算
	tensu += h[x][y] * 1;

	return tensu;
}

