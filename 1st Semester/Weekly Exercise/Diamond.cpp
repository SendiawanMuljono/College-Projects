#include<stdio.h>
#include<string.h>

int main(){
//	FILE *fp = fopen("testdata.in","r");
	int t,ubah,count,arrCount[26],arrChar[26],arrKar[26],index,p=1,k=2,count2 = 1,d=1,index2;
	char a,b;
	char nama[101];
	
	scanf("%d",&t);
	for(int x = 0;x<t;x++){
		count = 0;index=0;count2=1;p=1;index2=0;
		scanf("%s",nama);
		scanf("%d",&ubah);
		for(int y = 0;y<ubah;y++){
			count = 0;k=2;d=1;
			scanf(" %c %c",&a,&b);
			for(int z = 0;z<strlen(nama);z++){		
				k=2;	
				for(int u = 0;u<index;u++){
					if(z== arrChar[u]){
						k=1;
						break;
					}
				}
				if(k!=1){
					if(nama[z] == a){
						nama[z] = b;
						arrChar[index] = z;
						index++;
					}
				}
//				if(nama[z] == a){
//				}		
			}
//			if(k!=1){
//				if(d == 0){
//					arrChar[index] = b;
//					index++;
//				}
//			}
		}
		for(int q = 0; q<strlen(nama);q++){
			p=1;count2=1;
			for(int w = q+1;w<strlen(nama);w++){
				if(nama[q] == nama[w]){
					count2++;
				}
				for(int b =0;b<index2;b++){
					if(nama[q] == arrKar[b]){
						p=0;
						break;
					}
				}
				if(p==0){
					break;
				}
			}
			if(q==strlen(nama)-1){
				for(int b =0;b<index2;b++){
					if(nama[q] == arrKar[b]){
						p=0;
						break;
					}
				}
			}
			if(p!=0){
				arrKar[index2] = nama[q];
				arrCount[index2] = count2;
				index2++;
			}
		}
		for(int u = 0;u<index2;u++){
			for(int j = u+1;j<index2;j++){
				if(arrKar[u]>arrKar[j] && arrKar[j]!=NULL){
					int temp = arrKar[u];
					arrKar[u]=arrKar[j];
					arrKar[j]=temp;
					int temp2 = arrCount[u];
					arrCount[u]=arrCount[j];
					arrCount[j]=temp2;
				}
			}
		}
		for(int i = 0;i<index2;i++){
			printf("%c %d\n",arrKar[i],arrCount[i]);
		}
		memset(arrChar,0,sizeof(arrChar));
		memset(arrCount,0,sizeof(arrCount));
		memset(arrKar,0,sizeof(arrKar));
	}
	return 0;
}
