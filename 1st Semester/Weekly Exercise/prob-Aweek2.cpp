#include<stdio.h>

int main(){
	long long int a,b,c,d,x,y;
	scanf("%lld %lld %lld %lld", &a, &b,&c,&d);
	
	x = a*b;
	y = c+d;
	
	if(x>y){
		printf("True\n");
	}
	else{
		printf("False\n");
	}
	
	return 0;
}
