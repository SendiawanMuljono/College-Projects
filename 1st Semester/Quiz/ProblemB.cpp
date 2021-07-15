#include "stdio.h"
#include "math.h"
	int main()
		{
			int act,rep;
			scanf("%d",&act);
			
				for(int t=1;t<=act;t++)
					{
						scanf("%d",&rep);
						printf("Case #%d:\n",t);
						
						for(int s=1;s<=rep;s++)
							{
								if(s%15==0)
								{
									printf("%d Lili\n",s);
								}
								else if(s%3==0 || s%5==0)
								{
								printf("%d Jojo\n",s);	
								}
								else
								{
									printf("%d Lili\n",s);
								}
							}
					}
		}
