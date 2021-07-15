#include<stdio.h>

int main(){
	int a = 0, b = 0, sum = 0;
	scanf("%d", &a);
	
	for(int x = 0; x<a;x++){
		scanf("%d", &b);
		sum += b;
		if(sum>=40){
			sum = sum - 40;
		}
		else if(sum == 30){
			sum = 10;
		}
		else if(sum == 12){
			sum = 28;
		}
		else if (sum == 35){
			sum = 7;
		}
	}
	printf("%d\n", sum);
	
	return 0;
}
