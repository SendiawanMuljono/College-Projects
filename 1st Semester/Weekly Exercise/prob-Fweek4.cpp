#include<stdio.h>

int fib(int x){
	if(x<0){
		return 0;
	}
	else if(x<2){
		return x;
	}
	return fib(x-1) + fib(x-3);
}

int main(){
	int x;
	scanf("%d",&x);
	printf("%d\n",fib(x));
	
	return 0;
}
