#include<stdio.h>
#include<string.h>

int main(){
	FILE *fp = fopen("testdata.in","r");
	int index,t,ubah,noChange[26],arrKar[26],arrCount[26],index2,o=0,count,p;
	char a,b;
	char nama[101];
	
	fscanf(fp,"%d",&t);
	for(int x = 0;x<t;x++){
		index=0;count=1;index2=0;
		fscanf(fp,"%s",nama);
		fscanf(fp,"%d",&ubah);
		for(int y = 0;y<ubah;y++){
			o=0;count=0;
			fscanf(fp," %c %c",&a,&b);
			for(int k = 0;k<index;k++){
				if(a == noChange[k]){
					o = 1;
				}
			}
			if(o!=1){
				for(int i =0;i<strlen(nama);i++){
					if(nama[i] == a){
						nama[i] = b;
					}
				}
				noChange[index] = a;
				index++;
			}
		}
		for(int q = 0; q<strlen(nama);q++){
			p=1;count=1;
			for(int w = q+1;w<strlen(nama);w++){
				if(nama[q] == nama[w]){
					count++;
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
				arrCount[index2] = count;
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
		for(int h = 0;h<index2;h++){
			printf("%c %d\n",arrKar[h],arrCount[h]);
		}
	}
	return 0;
}
