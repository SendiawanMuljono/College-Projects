#include "stdio.h"
#include "string.h"
#include "math.h"
	int main()
		{
			int act,tnd,hasil,pjg,buka,result,A,B;
			char string[103]={};
			char copy[103]={};
			scanf("%d",&act);
			
				for(int h=1;h<=act;h++)
					{
						tnd=0;hasil=0;buka=0;result=0;A=0;B=0;
						scanf("%s",string);
					
					pjg = strlen(string);
					for(int u=0;u<pjg;u++)
						{
							if(string[u] == '(')
							{
								buka =1;
							
							}
							else if(string[u] == ')')
							{
								buka = 0;
							
							}
							
							if(string[u] == '-')
							{
							
							}
							
							if(string[u] != '-'&& string[u] !='(' && string[u] != '-' && buka==1)
							{
								string[u] = '2';
							}
							if(string[u] != '-'&& string[u] !='(' && string[u] != '-' && buka==0)
							{
								string[u] = string[u];
							}
							
						}
						
						for(int j=0;j<pjg;j++)
							{
							if(string[j] == ')' || string[j] =='(' || string[j] == '-')
							{
								
							}
							else
							{
								copy[tnd] = string[j];
									tnd++;
							}
							
							}
						
						for(int s=0;s<strlen(copy);s++)
						{
							if(copy[s] == '1' )
							
							{
								A=strlen(copy)-1-s;
							}
							if(copy[s]=='2')
							{
								B=strlen(copy)-1-s;
							}
							
							if(copy[s] == '1')
							{
								A=pow(2,A);
//							A=1<<A;
								result = result + A;
							}
							else if(copy[s]== '2')
							{
								B=pow(2,B);
								B = B* -1;
								result = result + B;
							}
							
							
							
						}
//						printf("%d %d\n",A,B);
						
printf("Case #%d: %d\n",h,result);

					}
						
				
		}
