#include<stdio.h>

int main(){
	FILE *fp = fopen("testdata.in","r");
	int t,jmlh,pasti,count,keliling,luas;
	
	fscanf(fp,"%d",&t);
	for(int x = 1;x<=t;x++){
		pasti = 0;luas=0;count=0;keliling=0;
		fscanf(fp,"%d",&jmlh);
		int num[jmlh];
		for(int y = 0;y<jmlh;y++){
			fscanf(fp,"%d",&num[y]);
			luas+=num[y];
		}
		pasti = (jmlh*2)*2 + num[0]*2 + num[jmlh-1]*2;
		for(int z = 0;z<jmlh-1;z++){
			if(num[z]>=num[z+1]){
				count+=num[z]-num[z+1];
			}
			else{
				count+=(num[z]-num[z+1])*-1;
			}
		}
		keliling = pasti + count*2;
		
		printf("Case #%d: %d %d\n",x,keliling,luas*4);
	}
	
	return 0;
}
