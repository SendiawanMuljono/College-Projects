#include<stdio.h>
//#include<conio.h>

int rowG,columnG,count=0;

//void printMap(char map[][102]){
//	printf("\n");
//	for(int y = 0;y<rowG;y++){
//		printf("%s\n",map[y]);
//	}
//	printf("\n");
////	getch();
//}

void floodfill(char map[][102], int row, int column){
	if(row<0||column<0||row>=rowG||column>=columnG){
		return;
	}
	if(map[row][column] =='S'||map[row][column] == 'F'||map[row][column]=='O'){
		return;
	}
	if(map[row][column] == 'K'){
		count++;
	}
	
	map[row][column] = 'O';
	floodfill(map,row+1,column);
	floodfill(map,row-1,column);
	floodfill(map,row,column+1);
	floodfill(map,row,column-1);
}

int main(){
	char map[102][102];
	int t;
	scanf("%d",&t);
	for(int x=1;x<=t;x++){
		count = 0;
		scanf("%d %d",&rowG, &columnG);
		for(int y=0;y<rowG;y++){
			scanf("%s",map[y]);
		}
		for(int i = 0;i<rowG;i++){
			for(int j = 0;j<columnG;j++){
				if(map[i][j] == 'H'){
					floodfill(map,i,j);
				}
			}
		}
		printf("Case #%d: %d\n",x,count);
	}
	
	
	return 0;
}

//2
//3 3
//SSS
//SHS
//KSS
//4 5
//SKKKS
//SKKKS
//SSHSS
//SSSSS

