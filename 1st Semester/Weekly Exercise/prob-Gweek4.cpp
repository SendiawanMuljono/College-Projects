#include<stdio.h>
#include<string.h>
//#include<conio.h>

int chess[8][8];

//void viewAll(){
//	for(int x = 0;x<8;x++){
//		for(int y = 0;y<8;y++){
//			printf("%d ",chess[x][y]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//	getch();
//}


void floodfillHitam(int langkah,int barisHitam, int kolomHitam){
	for(int h = 0;h<8;h++){
		for(int g = 0;g<8;g++){
			if(chess[h][g]>=3){
				return;
			}
		}
	}	
	if(chess[barisHitam][kolomHitam] == 1||barisHitam<0||kolomHitam<0||barisHitam>=8||kolomHitam>=8){
		return;
	}
	if(langkah == 0){
		return;		
	}
	chess[barisHitam][kolomHitam] = 1+chess[barisHitam][kolomHitam];
//	viewAll();
	/*
	yang ___|
		   |
	*/
	floodfillHitam(langkah-1,barisHitam-1,kolomHitam+2);
	floodfillHitam(langkah-1,barisHitam+1,kolomHitam+2);
	/*
	yang ___
	      |
	     |
	*/
	floodfillHitam(langkah-1,barisHitam-2,kolomHitam-1);
	floodfillHitam(langkah-1,barisHitam-2,kolomHitam+1);
	/*
	yang |__
	    |
	*/
	floodfillHitam(langkah-1,barisHitam-1,kolomHitam-2);
	floodfillHitam(langkah-1,barisHitam+1,kolomHitam-2);
	/*
	yang   |
		__|__
	*/
	floodfillHitam(langkah-1,barisHitam+2,kolomHitam-1);
	floodfillHitam(langkah-1,barisHitam+2,kolomHitam+1);
}

void floodfillPutih(int langkah,int barisPutih, int kolomPutih){
//	viewAll();
	for(int h = 0;h<8;h++){
		for(int g = 0;g<8;g++){
			if(chess[h][g]>=3){
				return;
			}
		}
	}
	if(chess[barisPutih][kolomPutih] == 2||barisPutih<0||kolomPutih<0||barisPutih>=8||kolomPutih>=8){
		return;
	}
	if(langkah == 0){
		return;		
	}
	chess[barisPutih][kolomPutih] = 2+chess[barisPutih][kolomPutih];
	floodfillPutih(langkah-1,barisPutih-1,kolomPutih+2);
	floodfillPutih(langkah-1,barisPutih+1,kolomPutih+2);
	/*
	yang   |
		__|__
	*/
	floodfillPutih(langkah-1,barisPutih+2,kolomPutih-1);
	floodfillPutih(langkah-1,barisPutih+2,kolomPutih+1);
	/*
	yang |__
	    |
	*/
	floodfillPutih(langkah-1,barisPutih-1,kolomPutih-2);
	floodfillPutih(langkah-1,barisPutih+1,kolomPutih-2);
	/*
	yang ___
	      |
	     |
	*/
	floodfillPutih(langkah-1,barisPutih-2,kolomPutih-1);
	floodfillPutih(langkah-1,barisPutih-2,kolomPutih+1);
}


int main(){
	int t,kolomHitam, kolomPutih,barisHitam,barisPutih;
	int langkah,count=0;
	char hitam[10],putih[10];
	scanf("%d",&t);
	for(int x = 1;x<=t;x++){
		scanf("%d",&langkah);
		scanf("%s %s",hitam,putih);
		kolomHitam = hitam[0]%65;
		barisHitam = 8-hitam[1]%48;
		kolomPutih = putih[0]%65;
		barisPutih = 8-putih[1]%48;
		floodfillHitam(langkah+1,barisHitam,kolomHitam);
		floodfillPutih(langkah+1,barisPutih,kolomPutih);
		for(int h = 0;h<8;h++){
			for(int g = 0;g<8;g++){
				if(chess[h][g]>=3){
					count++;
				}
			}
		}
//		viewAll();
		if(count>0){
			printf("Case #%d: YES\n",x);
		}
		else{
			printf("Case #%d: NO\n",x);
		}
		memset(chess,0,sizeof(chess));
		count = 0;
	}
	return 0;
}
