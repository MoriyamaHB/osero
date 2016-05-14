#include<stdio.h>
#include<Windows.h>
#include"osero.h"
#include"osero_mori.h"
#include"tosero.h"

#define TAIKI 3//AIの待機時間

int mass[8][8];
int x, y;
int end_flag = 0,i=0;

void AI1(void);
void AI2(void);
void user1(void);
void user2(void);

int main(void){
	mass_ini(mass);
	print_osero(mass);

	while (calc_bw(mass,0)!=0){//マスが全て埋まるまで繰り返す

//--------------------先手--------------------------------

		//AI(先手)のターン
		AI1();

		//ユーザー(先手)のターン
		//user1();

		if (end_flag >= 2)//どちらもパスした時
					break;
				if(calc_bw(mass,0)==0)//すべて埋まってたら終了
					break;
	
//---------------------後手--------------------------------

		//AI(後手)のターン
		AI2();

		//ユーザー(後手)のターン
		//user2();

		if (end_flag >= 2)//どちらもパスした時
			break;
	}
	terminate_osero(mass);//終了
	return 0;
}

//AI(先手)のターン
void AI1(void){
	printf("\n--------------------------------------------------\n");
	printf("<● のターン>");
		Sleep(TAIKI);
	if (mori_main(mass, 1, &x, &y) == 0){//AIから座標を受け取る
		if (convert_osero_main(mass, 1, x, y) == 0){//設置
			printf("(%d,%d)\n", x, y);
			print_osero(mass);
			end_flag=0;
		}
		else{//設置不可能な場所に置こうとした時
			end_flag++;
			printf("● はパスしました");
		}
	}//AIが-1を返した時
	else{
		end_flag++;
		printf("● はパスしました");
	}
}

//AI(後手)のターン
void AI2(void){
	printf("\n--------------------------------------------------\n");
	printf("<○ のターン>");
		Sleep(TAIKI);
	if (oseroHyouka(mass, -1, &x, &y) == 0){//AIから座標を受け取る
		if (convert_osero_main(mass, -1, x, y) == 0){//設置
			printf("(%d,%d)\n", x, y);
			print_osero(mass);
			end_flag=0;
		}
		else{//設置不可能な場所に置こうとした時
			end_flag++;
			printf("○ はパスしました");
		}
	}//AIが-1を返した時
	else{
		end_flag++;
		printf("○ はパスしました");
	}
}

//ユーザー(先手)のターン
void user1(void){
	printf("\n--------------------------------------------------\n");
	printf("<● のターン>\n");
	do{
		printf("入力(設置不可なときは(-1,-1)を入力):");
		scanf("%d,%d", &x, &y);//入力
		if (x == -1 && y == -1){//-1,-1でパス
			printf("● はパスしました\n");
			end_flag=0;
			break;
		}
		if ((convert_osero_main(mass, 1, x, y) == 0 && mass_judge(x, y) == 1)){
			//設置可能な場所 && 範囲内である時
			end_flag--;
			print_osero(mass);
			break;//ループを抜ける
		}
	} while (1);//正常に入力されるまで繰り返す
}

//ユーザー(後手)のターン
void user2(void){
	printf("\n--------------------------------------------------\n");
	printf("<○ のターン>\n");
	do{
		printf("入力(設置不可なときは(-1,-1)を入力):");
		scanf("%d,%d", &x, &y);//入力
		if (x == -1 && y == -1){//-1,-1でパス
			printf("○ はパスしました\n");
			end_flag=0;
			break;
		}
		if ((convert_osero_main(mass, -1, x, y) == 0 && mass_judge(x, y) == 1)){
			//設置可能な場所 && 範囲内である時
			print_osero(mass);
			end_flag--;
			break;//ループを抜ける
		}
	} while (1);//正常に入力されるまで繰り返す
}

