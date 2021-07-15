#include "stdio.h"
#include "string.h"
#include "math.h"
int main()
	{
		long int act,pjg,tanda=0,hasil,nilai,index;
		char string[200]={};
		char string2[200]={};
		scanf("%ld",&act);
		
		for(int repetition=1;repetition<=act;repetition++)
			{
				tanda=0;hasil=0;nilai=0;
				scanf("%s",string);
				pjg=strlen(string);
				
				for(int j=0;j<pjg;j++)
					{
						if(string[j]=='(')
							{
								string[j+2]= '2';
							}
					}
			
			for(int s=0;s<pjg;s++)
				{
					if(string[s]== '1' || string[s]=='2' || string[s]=='0')
					{
						string2[tanda] = string[s];
						tanda++;
						
					}
				}
				
				int pjg2;
				pjg2=strlen(string2);
			
				for(int y=0;y<pjg2;y++)
					{
						if(string2[y] == '1')
							{
								index = tanda-y-1;
								nilai = pow(2,index);
								hasil = hasil+nilai;
//								printf("%d\n",y);
							}
							
						if(string2[y] == '2')
						{
							index = tanda-y-1;
								nilai = pow(2,index);
								hasil= hasil-nilai;
//								printf("%d\n",y);
						}
					}
			printf("Case #%d: %ld\n",repetition,hasil);
			}
	}
