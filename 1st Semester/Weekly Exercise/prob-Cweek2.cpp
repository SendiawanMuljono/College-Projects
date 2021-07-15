#include<stdio.h>

int main(){
	int d = 0, s = 0, t = 0;
	scanf("%d %d %d", &d, &s, &t);
	if(d>s && d>t){
		printf("Daging\n");
		if(s>t){
			printf("Sayur\nTelur\n");
		}
		else{
			printf("Telur\nSayur\n");
		}
	}
	else if(s>d && s>t){
		printf("Sayur\n");
		if(d>t){
			printf("Daging\nTelur\n");
		}
		else{
			printf("Telur\nDaging\n");
		}
	}
	else if(t>d && t>s){
		printf("Telur\n");
		if(d>s){
			printf("Daging\nSayur\n");
		}
		else{
			printf("Sayur\nDaging\n");
		}
	}
	
	return 0;
}
