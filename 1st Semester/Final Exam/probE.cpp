#include<stdio.h>

int main(){
	int t,n,m,w,h,count,weight,valid;
	scanf("%d",&t);
	for(int x = 1;x<=t;x++){
		valid = 0;
		count = 2000000000;
		scanf("%d %d",&n,&m);
		for(int y = 0;y<n;y++){
			scanf("%d %d",&w,&h);
			int total = w+h;
			if(total>=m && total<count){
				count = total;
				weight = w;
				valid = 1;
			}
		}
		printf("Case #%d: ",x);
		if(valid == 1){
			printf("%d\n",weight);
		}
		else{
			printf("Impossible\n");
		}
	}
	
	
	return 0;
}
