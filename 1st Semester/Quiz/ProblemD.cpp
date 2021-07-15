#include "stdio.h"
	int main()
		{
	double bagi=999,angka,hasil;
			
				for(int j=1;j<=3;j++)
					{
						scanf("%lf",&angka);
						if(angka <10)
						{
							printf("0.00%.lf...\n",angka);
						}
						else if(angka>9 && angka<100)
							{
								printf("0.0%.lf...\n",angka);
							}
						else if(angka>99 && angka<1000)
							{
								if(angka == 111 ||angka == 222 ||angka == 333 ||angka == 444 ||angka == 555 ||angka == 666 ||angka == 777 ||angka == 888 )
								
								{
									hasil = angka/111;
									printf("0.%.lf...\n",hasil);
									
								}
								else
								{
									printf("0.%.lf...\n",angka);
								}
							}
							
						
					}
			
		}
