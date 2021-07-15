#include<stdio.h>
#include<string.h>

struct data{
	char name[101];
	char gender[101];
	char division[101];
};

int main(){
	char nama[101];
	int process,choose,tukar1,tukar2,resign,h,retire,k;
	struct data employee,arrEmployee[101],temp;
	for(int a = 0;a<101;a++){
		strcpy(arrEmployee[a].name,"***");
	}
	scanf("%d",&process);
	int index = 0;
	for(int x =0;x<process;x++){
		h=0;k=0;
		scanf("%d",&choose);
		if(choose == 1){
			scanf("%s",nama);
			scanf("%s",gender);
			scanf("%s",division);
			for(int y = 0;y<index;y++){
				if(strcmp(nama,arrEmployee[y].name)==0){
					h--;
					break;
				}
			}
			if(h == 0){
				for(int z = 0;z<index;z++){
					if(strcmp(arrEmployee[z].name,"mundur") == 0){
						strcpy(arrEmployee[z].name,nama);
						k++;
						break;
					}
				}
				if(k==0){
					strcpy(arrEmployee[index].name,nama); 
					index++;	
				}
			}
		}
		else if(choose == 2){
			scanf("%d %d",&tukar1, &tukar2);
			if(strcmp(arrEmployee[tukar1-1].name,"mundur")!=0&&strcmp(arrEmployee[tukar1-1].name,"***")!=0&&strcmp(arrEmployee[tukar1-1].name,"perm")!=0&&strcmp(arrEmployee[tukar2-1].name,"mundur")!=0&&strcmp(arrEmployee[tukar2-1].name,"***")!=0&&strcmp(arrEmployee[tukar2-1].name,"perm")!=0){
					temp = arrEmployee[tukar1-1];
					arrEmployee[tukar1-1] = arrEmployee[tukar2-1];
					arrEmployee[tukar2-1]= temp;			
			}
		}
		else if(choose == 3){
			scanf("%d",&resign);
			if(strcmp(arrEmployee[resign-1].name,"***")!=0&&strcmp(arrEmployee[resign-1].name,"perm")!=0){
				strcpy(arrEmployee[resign-1].name,"mundur");
			}
		}
		else if(choose == 4){
			scanf("%d",&retire);
			if(strcmp(arrEmployee[retire-1].name,"***")!=0&&strcmp(arrEmployee[retire-1].name,"mundur")!=0){
				strcpy(arrEmployee[retire-1].name,"perm");
			}
		}
	}
	for(int y = 0;y<index;y++){
		if(strcmp(arrEmployee[y].name,"mundur") != 0 && strcmp(arrEmployee[y].name,"perm")!=0 && strcmp(arrEmployee[y].name,"***")!=0){			
			printf("%s\n",arrEmployee[y].name);
		}
	}
	return 0;
}
