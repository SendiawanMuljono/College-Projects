#include <stdio.h>
#include <string.h>


char denah[100][100];

void fire(int positionX,int positionY,int batas,int second)
{
		for(int i=0;i<batas;i++){
			for(int j=0;j<batas;j++){
				if(i> positionX-second && i<positionX+second &&j>positionY-second && j<positionY+second ){
					denah[i][j]='F';
				}
			}
		}
}


int main()
{
	int testcase;
	int n;
	int second;
	
	FILE *file=fopen("awd.txt","r");
	
	fscanf(file,"%d\n",&testcase);
	for(int k=1;k<=testcase;k++)
	{
		fscanf(file,"%d %d\n",&n,&second);
		
		for(int i=0;i<n;i++)
		{
			fscanf(file,"%s\n",denah[i]);
		}
	
		printf("Case #%d:\n",k);
		int selesai=0;
		int positionX;
		int positionY;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(denah[i][j]=='F')
				{
					selesai=1;
					positionX=i;
					positionY=j;
					break;
				}
			}
			if(selesai==1)
			{
				break;
			}
		}
		
		fire(positionX,positionY,n,second);
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				printf("%c",denah[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		
		
	}
	return 0;
}
