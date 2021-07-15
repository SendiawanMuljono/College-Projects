//TOLONG KENAPA CUMAN DPT NILAI 60 PDHL UDH NYOBA BYK TEST CASE BENER :(
#include<stdio.h>
//#include<conio.h>

char map[101][101];
int count = 0,rowG,columnG;

//void printMap(){
//	for(int i = 0;i<5;i++){
//		printf("%s\n", map[i]);
//	}
//	getch();
//	
//}

void floodfill(int row, int column){
	map[row][column] = 'O';
	if(map[row-1][column] == '.' && row-1>-1){
		floodfill(row-1,column);//atas	
	}
	if(map[row][column-1]=='.'&& column-1>-1){
		floodfill(row,column-1);//kiri
	}
	if(map[row+1][column] == '.' && row+1<rowG){
		floodfill(row+1,column);//bawah
	}
	if(map[row][column+1] == '.' && column+1<columnG){
		floodfill(row,column+1);//kanan
	}
	if(map[row-1][column] == '*' && row-1>-1){
		count++;
		floodfill(row-1,column);//atas	
	}
	if(map[row][column-1]=='*'&& column-1>-1){
		count++;
		floodfill(row,column-1);//kiri
	}
	if(map[row+1][column] == '*' && row+1<rowG){
		count++;
		floodfill(row+1,column);//bawah
	}
	if(map[row][column+1] == '*' && column+1<columnG){
		count++;
		floodfill(row,column+1);//kanan
	}
//	printMap();
}

int main(){
	int t;
	scanf("%d", &t);
	for(int x = 1;x<=t;x++){
		scanf("%d %d",&rowG,&columnG);
		for(int h = 0;h<rowG;h++){
			scanf("%s", map[h]);		
		}
		for(int z =0;z<rowG;z++){
			for(int y=0;y<columnG;y++){
				if(map[z][y] == 'P'){
					floodfill(z,y);
				}
			}
		}
		printf("Case #%d: %d\n",x,count);
		count = 0;
	}
//	for(int x =0;x<row;x++){
//		for(int y=0;y<column;y++){
//			printf("%c",map[x][y]);
//		}
//		printf("\n");
//	}
//2
//5 5
//#####
//#P..#
//###.#
//#*.*#
//#####
//5 5
//#####
//#P#*#
//#####
//#*.*#
//#####

	return 0;
}


