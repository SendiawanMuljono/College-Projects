#include "stdio.h"
	int main()
		{
			int act,car,spasi;
			char string[300]={};
			scanf("%d",&act);
			for(int j=1;j<=act;j++)
				{
					 spasi=0;
					scanf("%d\n",&car);
					scanf("%[^\n]",string);
					
				
				
					
					for(int s=0;s<car;s++)
						{
							if(string[s]!=' '&&spasi==0)
							{
								
							}
							
								
							
							if(string[s] == ' '&&spasi==0)
							{
								spasi=1;
								string[s]='`';
							}
							else if(string[s] == ' '&&spasi==1)
							{
								spasi=0;
							}
							
							if(string[s]!=' '&&spasi==1)
							{
								string[s]='`';
							}
							
						
						}
							printf("Case #%d: ",j);	
						for(int s=0;s<car;s++)
						{
							if(string[s] != '`')
							{
								printf("%c",string[s]);
							}
						}
						printf("\n");
				}
		}
