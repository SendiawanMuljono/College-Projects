#include "stdio.h"
#include "math.h"
	int main()
		{
			 int act;
			long long int hasilakhir,a,b,konstanta=1000000007,hasil1,hasil2;
			 scanf("%d",&act);
			 
			 for(int j=1;j<=act;j++)
			 	{
			 		hasilakhir=0;hasil1=1;hasil2=1;
			 		scanf("%lld %lld",&a,&b);
			 		
			 		while(a>15)
			 		{
			 			hasil1=(hasil1*pow(2,15));
			 			a-=15;
			 			hasil1=hasil1%konstanta;
					 }
					 
					 hasil1=hasil1*(pow(2,a));
					 hasil1=hasil1%konstanta;
					 
					 	while(b>10)
			 		{
			 			hasil2=(hasil2*pow(3,10));
			 			b-=10;
			 			 hasil2=hasil2%konstanta;
					 }
					 
					 hasil2=hasil2*(pow(3,b));
					hasil2=hasil2%konstanta;
					 
			 		
			 
hasilakhir=(hasil1*hasil2)%konstanta;
			 		printf("%lld\n",hasilakhir);
				 }
			 	
			
		}
