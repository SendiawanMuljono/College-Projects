#include<stdio.h>

int main(){
	int t,count = 0,i=3;
	scanf("%d",&t);
	count+=i;
	for(int a = 1;a<t;a++){
		count+=i;
		i+=1;
	}
	printf("%d\n",count);
	
	return 0;
}
