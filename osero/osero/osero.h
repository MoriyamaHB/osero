#ifndef ___osero
#define ___osero

//マスの初期化
void mass_ini(int m[8][8]);

//範囲内なら1,外なら0を返す
int mass_judge(int x, int y);

//マスの描画
void print_osero(int m[8][8]);

//マスの変更(main用)
int convert_osero_main(int m[8][8], int bw, int x, int y);

//マスの変更
void convert_osero(int m[8][8],int bw,int x,int y);

//マスの変更実行
static void change(int m[8][8],int bw,int x,int y,int s,int t,int vx,int vy);

//マスの描画
void print_osero(int m[8][8]);

//オセロの終了処理
void terminate_osero(int m[8][8]);

//コピー(a→bに代入します)
void  copy(const int a[8][8], int b[8][8]);

//第二引数と一致する整数の数を返す
int calc_bw(const int m[8][8], int bw);

#endif
