#include<stdio.h>

int main(){
	int q,t,jml,arr[10000],countOdd,countEven;
	scanf("%d",&jml);
	for(int a = 0;a<jml;a++){
		scanf("%d",&arr[a]);
	}
	scanf("%d",&t);
	for(int x = 1;x<=t;x++){
		countOdd= 0;countEven=0;
		scanf("%d",&q);
		for(int i = 0;i<jml-1;i++){
			for(int j = i+1;j<jml;j++){
				if(arr[i] % 2 == 0 && arr[j]%2 == 0){
					int tempEven = arr[i]+arr[j];
					if(tempEven >= q){
						countEven++;
					}
				}
				else if(arr[i] %2==1 && arr[j]%2 == 1){
					int tempOdd = arr[i]+arr[j];
					if(tempOdd>=q){
						countOdd++;
					}
				}
			}
		}
		printf("Case #%d: %d %d\n",x,countOdd,countEven);
	}
	
	return 0;
}
