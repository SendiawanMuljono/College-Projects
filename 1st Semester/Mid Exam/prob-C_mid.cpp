#include<stdio.h>

int main(){
	int t,g=0;
	int arr[9][9], arr1[81], matrix1[9],matrix2[9],matrix3[9],matrix4[9],matrix5[9],matrix6[9],matrix7[9],matrix8[9],matrix9[9];
	scanf("%d", &t);
	double l = t,count = 0;
	for(int k = 1;k<=t;k++){
		for(int y = 0;y<9;y++){
			for(int z = 0;z<9;z++){
				scanf("%d", &arr[y][z]);
			}
		}
//		for(int y = 0;y<9;y++){
//			for(int z = 0;z<9;z++){
//				arr1[y*9+z] = arr[y][z];
//			}
//		}
//		int a = 0;
//		int b = 0;
//		while(b<=20){
//			matrix1[a] = arr1[b];
//			a++;b++;
//			if(b==3||b==12){
//				b+=6;
//			}
//		}
//		for(int u = 0;u<9;u++){
//			for(int y = u+1;y<9;y++){
//				if(matrix1[u] == matrix1[y]){
//					g = 1;
//				}
//			}
//		}
//		
//		int c = 0;
//		int d = 3;
//		while(d<=23){
//			matrix2[c] = arr1[d];
//			c++;d++;
//			if(d==6||d==15){
//				d+=6;
//			}
//		}
//		for(int u = 0;u<9;u++){
//			for(int y = u+1;y<9;y++){
//				if(matrix2[u] == matrix2[y]){
//					g = 1;
//				}
//			}
//		}
//		
//		int e = 0;
//		int f = 6;
//		while(f<=26){
//			matrix3[e] = arr1[f];
//			e++;f++;
//			if(f==9||f==18){
//				f+=6;
//			}
//		}
//		for(int u = 0;u<9;u++){
//			for(int y = u+1;y<9;y++){
//				if(matrix3[u] == matrix3[y]){
//					g = 1;
//				}
//			}
//		}
//		int h = 0;
//		int i = 27;
//		while(i<=47){
//			matrix4[h] = arr1[i];
//			h++;i++;
//			if(i==30||i==39){
//				i+=6;
//			}
//		}
//		for(int u = 0;u<9;u++){
//			for(int y = u+1;y<9;y++){
//				if(matrix4[u] == matrix4[y]){
//					g = 1;
//				}
//			}
//		}
//		int j = 0;
//		int z = 30;
//		while(k<=50){
//			matrix5[j] = arr1[z];
//			j++;z++;
//			if(z==33||z==42){
//				z+=6;
//			}
//		}
//		for(int u = 0;u<9;u++){
//			for(int y = u+1;y<9;y++){
//				if(matrix5[u] == matrix5[y]){
//					g = 1;
//				}
//			}
//		}
//		int m = 0;
//		int n = 33;
//		while(n<=53){
//			matrix6[m] = arr1[n];
//			m++;n++;
//			if(n==36||n==45){
//				n+=6;
//			}
//		}
//		for(int u = 0;u<9;u++){
//			for(int y = u+1;y<9;y++){
//				if(matrix6[u] == matrix6[y]){
//					g = 1;
//				}
//			}
//		}
//		int o = 0;
//		int p = 54;
//		while(p<=74){
//			matrix7[o] = arr1[p];
//			o++;p++;
//			if(p==57||p==66){
//				p+=6;
//			}
//		}
//		for(int u = 0;u<9;u++){
//			for(int y = u+1;y<9;y++){
//				if(matrix7[u] == matrix7[y]){
//					g = 1;
//				}
//			}
//		}
//		int q = 0;
//		int r = 57;
//		while(r<=77){
//			matrix8[q] = arr1[r];
//			q++;r++;
//			if(r==60||r==69){
//				q+=6;
//			}
//		}
//		for(int u = 0;u<9;u++){
//			for(int y = u+1;y<9;y++){
//				if(matrix8[u] == matrix8[y]){
//					g = 1;
//				}
//			}
//		}
//		int s = 0;
//		int u = 60;
//		while(u<=80){
//			matrix9[s] = arr1[u];
//			s++;u++;
//			if(u==63||u==72){
//				u+=6;
//			}
//		}
//		for(int u = 0;u<9;u++){
//			for(int y = u+1;y<9;y++){
//				if(matrix9[u] == matrix9[y]){
//					g = 1;
//				}
//			}
//		}
		for(int x = 0;x<9;x++){
			for(int u = 0 ;u<8;u++){
				for(int j =u+1;j<9;j++){
					if((arr[x][u] == arr[x][j])||(arr[u][x] == arr[j][x])){
						g = 1;
					}
				}			
			}
		}

		if(g == 1){
			printf("Case #%d: FALSE\n",k);
		}				
		else{
			printf("Case #%d: TRUE\n",k);
			count++;
		}
		g = 0;
	}	
	printf("%.2lf%%\n", (count/l)*100);
	return 0;
}

/*

2
1 2 3 4 5 6 7 8 9
4 5 6 7 8 9 1 2 3
7 8 9 1 2 3 4 5 6
2 3 4 5 6 7 8 9 1
5 6 7 8 9 1 2 3 4
8 9 1 2 3 4 5 6 7
3 4 5 6 7 8 9 1 2
9 1 2 3 4 5 6 7 8
6 7 8 9 1 2 3 4 5

1 3 4 7 2 5 9 8 6
5 2 7 6 9 8 1 3 4
9 8 6 1 3 4 5 7 2
3 7 9 4 2 1 6 5 8
4 5 1 9 8 3 2 6 7
2 4 5 3 6 7 8 9 1
6 9 8 5 7 2 4 1 3
8 1 3 2 5 6 7 2 4
7 6 2 8 1 9 3 4 5
*/
