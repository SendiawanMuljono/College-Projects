#include "stdio.h"
#include "math.h"
	int main()
		{
			long long int act,jml,kr,tg,kn,total,tanda;

			scanf("%lld",&act);
			
				for(int p=1;p<=act;p++)
					{
						total=0;tanda=1;
						scanf("%lld %lld %lld %lld",&jml,&kr,&tg,&kn);
						
						while(total<jml)
						{
							total = (kr*tanda)+(tg*(tanda+1))+(kn*(tanda+2));
							tanda++;
							
						}
					
					if(total==jml)
					{
						printf("Case #%d: %lld\n",p,tanda-1);
					}
					else
					{
						
					printf("Case #%d: -1\n",p);
					}
					
					}
		}
