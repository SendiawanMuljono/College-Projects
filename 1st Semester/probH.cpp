#include<stdio.h>
#include<math.h>

int main(){
	FILE *fp = fopen("testdata.in","r");
	int t;
	double num;
	fscanf(fp,"%d",&t);
	for(int x = 1;x<=t;x++){
		fscanf(fp,"%lf",&num);
		double total = pow(num,0.333333333333333333333333333333333333333333333333333333333333333333333333333333333);
		printf("Case #%d: %.0lf\n",x,total);
	}
	
	return 0;
}
