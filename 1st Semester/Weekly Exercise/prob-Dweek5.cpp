#include<stdio.h>

int main(){
	FILE *open = fopen("testdata.in","r");
	
	int A,B;
	

	fscanf(open,"%d %d",&A,&B);
	printf("%d\n",A+B);
	
	
	fclose(open);
	
	return 0;
}
