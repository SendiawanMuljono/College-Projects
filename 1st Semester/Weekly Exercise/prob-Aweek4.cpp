#include<stdio.h>


int main(){
	int x,y,k;
	
	scanf("%d %d %d",&x,&y,&k);
	if(x>y){
		printf("-1\n");
	}
	else if((x+y)/2 == k){
		printf("%d\n",y-k);
	}
	else{
		printf("-1\n");
	}
	
	return 0;
}
