#include<stdio.h>

int main(){
	int t,matriks,temp=0,count=0;
	scanf("%d",&t);
	for(int x = 1;x<=t;x++){
		scanf("%d",&matriks);
		int matriksJojo[matriks][matriks];
		int matriksLili[matriks][matriks];
		int matriksBibi[matriks][matriks];
		int matriksBaru[matriks][matriks];
		int matriksBaru2[matriks][matriks];
		//JOJO
		for(int y = 0;y<matriks;y++){
			for(int u = 0;u<matriks;u++){
				scanf("%d",&matriksJojo[y][u]);
			}
		}
		//LILI
		for(int y = 0;y<matriks;y++){
			for(int u = 0;u<matriks;u++){
				scanf("%d",&matriksLili[y][u]);
			}
		}
		//BIBI
		for(int y = 0;y<matriks;y++){
			for(int u = 0;u<matriks;u++){
				scanf("%d",&matriksBibi[y][u]);
			}
		}
		//KALI
		for(int y = 0;y<matriks;y++){
			for(int u = 0;u<matriks;u++){
				for(int g=0;g<matriks;g++){
					int result = matriksLili[y][g] * matriksBibi[g][u];
					temp+=result;	
				}
				matriksBaru[y][u] = temp;
				temp = 0;
			}
		}
		for(int y = 0;y<matriks;y++){
			for(int u = 0;u<matriks;u++){
				for(int g=0;g<matriks;g++){
					int result2 = matriksBaru[y][g] * matriksJojo[g][u];
					count+=result2;	
				}
				matriksBaru2[y][u] = count;
				count = 0;
			}
		}
		printf("Case #%d:\n",x);
		for(int i = 0;i<matriks;i++){
			for(int a = 0;a<matriks;a++){
				if(a==matriks-1){
					printf("%d",matriksBaru2[i][a]);
				}
				else{
					printf("%d ",matriksBaru2[i][a]);
				}
			}
			printf("\n");
		}
	}
	
	
	return 0;
}
