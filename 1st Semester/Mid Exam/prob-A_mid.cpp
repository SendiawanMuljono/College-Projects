#include<stdio.h>

int main(){
	int t = 0,chair, left,mid,right, z = 0,count = 0,n = 0;
	
	scanf("%d", &t);
	for(int x = 1;x<=t;x++){
		scanf("%d %d %d %d", &chair,&left,&mid,&right);
		while(n<1){
			z++;
			count++;
			if(left*z + mid *(z+1)+ right*(z+2) == chair){
				printf("Case #%d: %d\n",x, count);n = 2;
			}
			else if(left*z + mid *(z+1)+ right*(z+2) > chair){
				printf("Case #%d: %d\n",x, -1);n = 2;
			}
		}
		count = 0;z = 0;n=0;
	}
	
	
	return 0;
}
