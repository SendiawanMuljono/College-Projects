#include<stdio.h>


int main(){
	int t = 0,num = 0;
	long long int count = 0;
	scanf("%d",&t);
	for(int x = 1;x<=t;x++){
		count= 0;
		scanf("%d",&num);
		int temp = 1;
		for(long long int a = num-1;a>=1;a--){
			count += a*temp;
			temp++;
		}
		count+=num;
		printf("Case #%d: %lld\n",x,count);
	}
	
	return 0;
}
