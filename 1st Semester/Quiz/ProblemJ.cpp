#include "stdio.h"

int main()
	{
		int act,angka,puluhan,ratusan,ribuan,puluhribu,ratusribu,satuan;
		int ctr0,ctr1,ctr2,ctr3,ctr4,ctr5,ctr6,ctr7,ctr8,ctr9;
		scanf("%d",&act);
		
		for(int i=1;i<=act;i++)
			{
				ctr0=0;ctr1=0;ctr2=0;ctr3=0;ctr4=0;ctr5=0;ctr6=0;ctr7=0;ctr8=0;ctr9=0;
				puluhan=0;ratusan=0;ribuan=0;puluhribu=0;ratusribu=0;satuan=0;
				scanf("%d",&angka);
				
				/*Satuan*/
				
				if(angka <10)
				{
					for(int b=1;b<=angka;b++)
					{
					
					if(b==1)
							{
								ctr1++;
							}
								if(b==2)
							{
								ctr2++;
							}
								if(b==3)
							{
								ctr3++;
							}
								if(b==4)
							{
								ctr4++;
							}
								if(b==5)
							{
								ctr5++;
							}
								if(b==6)
							{
								ctr6++;
							}
								if(b==7)
							{
								ctr7++;
							}
								if(b==8)
							{
								ctr8++;
							}
								if(b==9)
							{
								ctr9++;
							}
							
								
					}
				}
				
				/*Puluhan*/
				
				else if(angka>9 && angka<100)
					{
							ctr1=1;ctr2=1;ctr3=1;ctr4=1;ctr5=1;ctr6=1;ctr7=1;ctr8=1;ctr9=1;satuan=0;puluhan=0;ctr0=0;
					for(int b=10;b<=angka;b++)
						{
							
							
							
							if(satuan==1||puluhan==1)
							{
								ctr1++;
							}
								if(satuan==2||puluhan==2)
							{
								ctr2++;
							}
								if(satuan==3||puluhan==3)
							{
								ctr3++;
							}
								if(satuan==4||puluhan==4)
							{
								ctr4++;
							}
								if(satuan==5||puluhan==5)
							{
								ctr5++;
							}
								if(satuan==6||puluhan==6)
							{
								ctr6++;
							}
								if(satuan==7||puluhan==7)
							{
								ctr7++;
							}
								if(satuan==8||puluhan==8)
							{
								ctr8++;
							}
								if(satuan==9||puluhan==9)
							{
								ctr9++;
							}
								if(satuan==0||puluhan==0)
							{
								ctr0++;
							}
							
							/*Reset*/
							if(satuan ==9)
							{
								satuan=0;
								puluhan++;
							}
							satuan++;
						}
					}
					/*Ratusan*/
					/*Ribuan*/
					/*Puluhribuan*/
					/*ratusribuan*/
					
					printf("Case #%d: %d %d %d %d %d %d %d %d %d %d\n",i,ctr0,ctr1,ctr2,ctr3,ctr4,ctr5,ctr6,ctr7,ctr8,ctr9);
			}
	}
