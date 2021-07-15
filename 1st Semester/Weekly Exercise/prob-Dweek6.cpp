#include<stdio.h>

int main(){
	FILE *fp = fopen("testdata.in","r");
	char map[100][100];
	int t,langkah,rowF,rowTemp,columnTemp;
	fscanf(fp,"%d",&t);
	for(int x = 1;x<=t;x++){
		fscanf(fp,"%d %d",&rowF,&langkah);
		for(int y = 0;y<rowF;y++){
			fscanf(fp,"%s",map[y]);
		}
		for(int i = 0;i<rowF;i++){
			for(int j = 0;j<rowF;j++){
				if(map[i][j] == 'F'){
					rowTemp = i;
					columnTemp = j;
					break;
				}
			}
		}	
		for(int p = rowTemp-langkah+1;p<=rowTemp+langkah-1;p++){
			for(int q = columnTemp-langkah+1;q<=columnTemp+langkah-1;q++){
				if(p<rowF && q<rowF&&p>=0&&q>=0){
					map[p][q] = 'F';
				}
			}
		}			
		printf("Case #%d:\n",x);
		for(int o = 0;o<rowF;o++){
			for(int u = 0;u<rowF;u++){
				printf("%c",map[o][u]);
			}
			printf("\n");
		}
		printf("\n");
	}	
	return 0;
}


