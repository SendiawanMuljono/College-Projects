#include<stdio.h>
#include<string.h>

int main(){
	int t = 0, i = 0, j = 0;
	
	scanf("%d",&t);
	char gambar[t][t],temp;
	j = t-1;
	for(int x = 0; x<t;x++){
		scanf("%s", gambar[x]);
	}
	for(int y = 0;y<t;y++){
		while(i<j){
			temp = gambar[y][i];
			gambar[y][i] = gambar[y][j];
			gambar[y][j] = temp;
			i++;j--;	
		}
		i = 0;j = t-1;
	}
	for(int x = t-1;x>=0;x--){
		for(int y = 0;y<t;y++){
			printf("%c", gambar[x][y]);
		}
		printf("\n");
	}
	
	return 0;
}
