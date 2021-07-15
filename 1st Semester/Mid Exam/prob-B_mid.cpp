#include<stdio.h>

int main(){
	int t = 0,a;
	scanf("%d",&t);
	for(int x = 1;x<=t;x++){
		scanf("%d", &a);
		printf("Case #%d:\n",x);
		for(int y = 1;y<=a;y++){
			if(y%15 == 0){
				printf("%d Lili\n",y);
			}
			else if(y%3 == 0 || y%5 == 0){
				printf("%d Jojo\n",y);
			}
			else{
				printf("%d Lili\n",y);
			}
		}
	}
	
	return 0;
}
