#include<stdio.h>
#include<string.h>

int main(){
	FILE *fp = fopen("testdata.in","r");
	int t,len,min,max,index=0,count=0,temp= 1,arrCount[100],total=0;
	char angka[100001];
	
	fscanf(fp,"%d",&t);
	
	for(int x = 1;x<=t;x++){
		count = 0;temp = 1;index=0;total=0;
		fscanf(fp,"%d %d %d",&len,&min,&max);
		fscanf(fp,"%s",angka);
		for(int y = 0;y<len;y++){
			if(angka[y] == '1'){
				count++;
				temp = 0;
			}
			else if(angka[y] == '0'){
				if(temp == 0 && count>=min && count<=max){
					arrCount[index] = count;
					index++;
				}
				temp = 1;
				count = 0;
			}
		}
		arrCount[index] = count;
		for(int z = 0;z<=index;z++){
			if(arrCount[z] >=min && arrCount[z]<=max){
				total+=1;
			}
		}
		printf("Case #%d: %d\n",x,total);
		memset(arrCount,0,sizeof(arrCount));
	}	
	return 0;
}
