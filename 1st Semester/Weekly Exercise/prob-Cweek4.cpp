#include<stdio.h>
#include<math.h>

int main(){
	int t,x,z;
	double y, euler = 2.72;
	scanf("%d",&t);
	for(int a = 1;a<=t;a++){
		scanf("%d",&x);
		scanf("%lf",&y);
		scanf("%d",&z);
		printf("Case #%d: ",a);
		double temp = y/z;
		double total = pow(x,temp);
		if(total<euler){
			printf("<\n");
		}
		else{
			printf(">\n");
		}
	}
	
	
	return 0;
}
