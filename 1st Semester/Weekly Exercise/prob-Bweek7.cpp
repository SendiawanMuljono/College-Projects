#include<stdio.h>
#include<string.h>

int main(){
	int arrNum[100000];
	int n,t,c,y;
	long long int nums;
	
	scanf("%d",&n);
	for(int u = 0;u<n;u++){
		scanf("%d",&arrNum[u]);
	}
	
	scanf("%d",&t);
	for(int x = 1;x<=t;x++){
		y=0;
		scanf("%lld",&nums);
		int i = 0;
		long long int test = arrNum[i];
		if(test>nums){
			y = 1;
			c = -1;
		}
		if(y!=1){
			for(int j = 1;j<n;j++){
				test += arrNum[j];
				if(j==1 && test>nums){
					c = 1;
				}
				else if(test>nums){
					break;
				}
				else{
					c = j+1;
				}
			}
		}
		printf("Case #%d: %d\n",x,c);
	}
	return 0;
}
