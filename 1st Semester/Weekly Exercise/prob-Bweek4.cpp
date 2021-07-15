#include<stdio.h>

int main(){
	int t, a,test;
	scanf("%d",&t);
	for(int x = 1;x<=t;x++){
		a=97;
		scanf("%d",&test);
		printf("Case #%d: ",x);
		for(int y = 0;y<test;y++){
			printf("%c",a);
			a++;
		}
		printf("\n");
	}
	
	return 0;
}
