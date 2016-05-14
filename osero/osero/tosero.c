#include<stdio.h>
#include<stdlib.h>
#include"osero.h"


int kazo(int x[8][8],int n){
    int i,j,sum = 0;
     for(i = 0; i < 8; i++){
            for(j = 0; j < 8; j++)
                if(x[i][j] == n)
                    sum++;
     }
     return sum;
}

int oseroHyouka(const int a[8][8],int n,int *x,int *y){

    int i,j;
    int sum = -1;
    int k[8][8];
    
    int l[8][8] = {{ 45, 3, 15, 14, 14, 15, 3, 45 },
	{ 3, 0, 12, 12, 12, 12, 0, 3 },
	{ 15, 12, 15, 14, 14, 15, 12, 15 },
	{ 14, 12, 14, 14, 14, 14, 12, 14 },
	{ 14, 12, 14, 14, 14, 14, 12, 14 },
	{ 15, 12, 15, 14, 14, 15, 12, 15 },
	{ 3, 0, 12, 12, 12, 12, 0, 3 },
	{ 45, 3, 15, 14, 14, 15, 3, 45 }
};
    for(i = 0; i < 8; i++){
            for(j = 0; j < 8; j++)
                if(a[i][j] == 0 ){
                    copy(a,k);
                    convert_osero(k,n,i,j);
                    if((kazo(a,n) < kazo(k,n) - 1) && sum <= l[i][j]){
                            sum = l[i][j];   
                            *x = i;
                            *y = j;
                    }
                }
    }
    if(sum == -1)
        return -1;
    else
        return 0;
}


                    

