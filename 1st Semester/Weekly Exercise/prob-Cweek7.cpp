#include<stdio.h>

int main(){
	int t,arr[25];
	int total;
	scanf("%d",&t);
	for(int x = 1;x<=t;x++){
		total = 0;
		for(int y = 0;y<25;y++){
			scanf("%d",&arr[y]);
			if(y>0){
				if(arr[0] == arr[y]){
					total++;
				}
			}
		}
		if(total == 24){
			printf("Case #%d: %d %d %d %d %d\n",x,arr[0]/2,arr[0]/2,arr[0]/2,arr[0]/2,arr[0]/2);
		}
		else{
			for(int i = 0;i<25;i++){
				for(int j = i+1;j<25;j++){
					if(arr[i]>arr[j]){
						int temp = arr[i];
						arr[i] = arr[j];
						arr[j] = temp;
					}
				}
			}
	//		for(int a = 0;a<25;a++){
	//			printf("%d ",arr[a]);
	//		}
			int angka1 = arr[0]/2;
			int angka2 = arr[1] - angka1;
			int angka3 = arr[4] - angka1;
			int angka5 = arr[24]/2;
			int angka4 = arr[23] - angka5;
			printf("Case #%d: %d %d %d %d %d\n",x,angka1,angka2,angka3,angka4,angka5);
		}
	}
		
	return 0;
}

//Input:
//5
//2 4 8 11 14 4 6 10 13 16 8 10 14 17 20 11 13 17 20 23 14 16 20 23 26
//14 16 8 11 23 20 23 2 4 26 10 13 16 8 10 14 17 20 11 14 4 6 13 17 20 
//642 1229 454 765 725 1229 1816 1041 1352 1312 454 1041 266 577 537 765 1352 577 888 848 725 1312 537 848 808
//5263 5536 9134 138 489 765 1038 4636 489 840 1116 1389 4987 765 1116 1392 1665 5263 1038 1389 1665 1938 5536 4636 4987
//1132 464 662 787 266 464 589 787 985 1330 589 787 912 1110 1455 787 985 1110 1308 1653 1132 1330 1455 1653 1998 
//
//Output:
//Case #1: 1 3 7 10 13
//Case #2: 1 3 7 10 13
//Case #3: 133 321 404 444 908
//Case #4: 69 420 696 969 4567
//Case #5: 133 331 456 654 999
