#include<stdio.h>

int main(){
	int x1,x2,x3;
	scanf("%d %d %d", &x1, &x2, &x3);
	if(x1 % 111 == 0){
		printf("0.%d...\n",x1%110);
	}
	else{
		printf("0.%.3d...\n",x1);
	}
	if(x2 % 111 == 0){
		printf("0.%d...\n",x2%110);
	}
	else{
		printf("0.%.3d...\n",x2);
	}
	if(x3 % 111 == 0){
		printf("0.%d...\n",x3%110);
	}
	else{
		printf("0.%.3d...\n",x3);
		
	}
	
	return 0;
}
