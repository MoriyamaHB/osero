#include<stdio.h>
#include"osero.h"

//マスの初期化
void mass_ini(int m[8][8]){
  int i, j;
  for (i = 0; i < 8; i++){
	for (j = 0; j < 8; j++)
	  m[i][j] = 0;//すべて0に初期化
  }
  m[3][3] = m[4][4] = 1;//初期配置セット
  m[3][4] = m[4][3] = -1;
}

//範囲内なら1,外なら0を返す
int mass_judge(int x, int y){
	if (x >= 0 && x < 8 && y >= 0 && y < 8)
		return 1;
	else
		return 0;
}

//マスの変更(main用)
int convert_osero_main(int m[8][8], int bw, int x, int y){
	int temp[8][8];
	int mae = calc_bw(m, bw),ato;
	copy(m, temp);
	convert_osero(temp, bw, x, y);
	ato = calc_bw(temp, bw)-1;
	if (mae >= ato){
		printf("エラー:ルール上設置不可能な場所です\n\n");
		return -1;
	}
	else{
		copy(temp, m);
		return 0;
	}
}

//マスの変更
void convert_osero(int m[8][8], int bw, int x, int y){
	int h,i, j;
	int vx[8]={0,1,1,1,0,-1,-1,-1};
	int vy[8]={-1,-1,0,1,1,1,0,-1};

	if (m[x][y] != 0)
		printf("エラー:すでに設置済みの場所です\n");
	else if (mass_judge(x, y) != 1){
		printf("エラー:範囲外です\n");
	}
	else{
		m[x][y] = bw;
		//8方向にたどる
		for(h=0;h<8;h++){
			for (i = x+vx[h], j = y+vy[h]; mass_judge(i, j); i+=vx[h],j+=vy[h]){
				if (m[i][j] == 0)
					break;
				if (m[i][j] == bw){
					change(m, bw, x, y, i, j, vx[h], vy[h]);
					break;
				}
			}
		}
	}
}

//マスの変更実行
static void change(int m[8][8], int bw, int x, int y, int s, int t, int vx, int vy){
	int i, j;
	if (mass_judge(x, y) != 1){
			printf("change<x,yが範囲外です\n");
	}
	else if (mass_judge(s, t) != 1){
			printf("change<s,tが範囲外です\n");
	}else{
			for (i = x + vx, j = y + vy; !(i == s && j == t) ; i += vx, j += vy){
				if (mass_judge(i, j) != 1){
					printf("change<s,tが見つけられませんでした\n");
					printf("bw:%d,x:%d,y:%d,s:%d,t:%d,vx:%d,vy:%d\n", bw, x, y, s, t, vx, vy);
					return;
				}
				m[i][j] = bw;
			}
	}
}

//マスの描画
void print_osero(int m[8][8]){
	int i, j;
	for (i = -1; i < 8; i++){
		for (j = -1; j < 8; j++){
			if (i < 0 && j < 0)
				printf(" 　");
			else if (j < 0)
				printf("%2d", i);
			else if (i < 0)
				printf("%2d", j);
			else{
				switch (m[j][i]){
				case 0:
					printf(" □");
					break;
				case -1:
					printf(" ○");
					break;
				case 1:
					printf(" ●");
					break;
				default:
					printf(" ? ");
				}
			}
		}
		putchar('\n');
	}
}

//オセロの終了処理
void terminate_osero(int m[8][8]){
	int t1=0, t2=0,i,j;
	printf("\n==========================================================\n");
	print_osero(m);//結果表示

	//枚数を計算
	for (i = 0; i < 8; i++){
		for (j = 0; j < 8; j++){
			if (m[i][j] == 1)
				t1++;
			else if (m[i][j] == -1)
				t2++;
		}
	}

	//勝者表示
	if (t1 > t2){
			printf("\n<<● の勝ちです>>\n");
			printf("● :%d枚,○ :%d枚\n\n",t1,t2);
		}
	else if (t1 < t2){
			printf("\n<<○ の勝ちです>>\n\n");
			printf("● :%d枚,○ :%d枚\n\n",t1,t2);
		}
	else
			printf("\n<<引き分けです>>\n\n");
}

//コピー(a→bに代入します)
void  copy(const int a[8][8], int b[8][8]){
	int i, j;
	for (i = 0; i < 8; i++){
		for (j = 0; j < 8; j++)
			b[i][j] = a[i][j];
	}
}

//第二引数と一致する整数の数を返す
int calc_bw(const int m[8][8], int bw){
	int i, j, temp = 0;
	for (i = 0; i < 8; i++){
		for (j = 0; j < 8; j++)
			if (m[i][j] == bw)
				temp++;
	}
	return temp;
}
