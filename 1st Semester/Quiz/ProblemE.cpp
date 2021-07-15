#include "stdio.h"

	int main(){
		int act,number,ctr,tandaarr,jml,sisa;
		int arrjml[2000]={};
		int arr[2000]={};
		scanf("%d",&act);
		for(int u=1;u<=act;u++){
			int tandaarr2=0;
			ctr=0;tandaarr=0;jml=0;
			
			for(int koko=0;koko<2000;koko++){
				arrjml[koko]=0;
			}
			
			scanf("%d",&number);
			printf("Case #%d:\n",u);
				
			/*Bikin angka prima*/
			for(int loop=2;loop<=number;loop++){
				ctr=0;
				for(int pembagi=2;pembagi<=loop;pembagi++){
					if(loop%pembagi ==0){
						ctr++;
					}
				}
				if(ctr==1){
					arr[tandaarr]=loop;	
					tandaarr++;
					jml++;
				}
			}
						
			/*Cari banyak faktor*/
			for(int loop=2;loop<=number;loop++){
				for(int hh=0;hh<jml;hh++){
					if(loop % arr[hh] ==0 ){
						sisa=loop/arr[hh];
						arrjml[hh]++;
						while(sisa % arr[hh] ==0 && sisa>0){
							sisa=sisa/arr[hh];
							arrjml[hh]++;	
						}
					}
				}
			}					
			for(int j=0;j<jml;j++){
				printf("%d %d\n",arr[j],arrjml[j]);
			}						
		}
		return 0;
	}
