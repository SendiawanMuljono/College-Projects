#include<stdio.h>
#include<conio.h>
int main(){
	int n = 0, j = 0;
	scanf("%d", &n);
	int arr[n][n], arr1[1];
	
	for(int x = 0;x<n;x++){
		for(int y = 0;y<n;y++){
			scanf("%d", &arr[x][y]);
		}
	}

	for(int x = 0;x<n;x++){
		for(int y = 0;y<n-1;y++){
			for(int z = y+1;z<n;z++){
				if((arr[x][y] == arr[x][z])||(arr[y][x] == arr[z][x])){
					j = 1;
				}
			}
		}
	}
	if(j == 1){
		printf("Nay\n");
	}
	else{
		printf("Yay\n");
	}
	system("cls");
	return 0;
}
