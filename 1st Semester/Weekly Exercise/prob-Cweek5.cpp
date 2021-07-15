#include<stdio.h>
struct student{
	char sCode[100];
	char sName[100];
	char sGender[100];
	char sFather[100];       
	char sMother[100];            
	char sSibling[100];             
};                            

struct lecturer{
	char lCode[100];
	char lName[100];
	char lGender[100];
	int lStudent[100];
	struct student murid[100];
};
						                 
							                   
int main(){     
	int t,k;	
	scanf("%d",&t);
	struct lecturer guru[t+1];
	
	for(int x = 0;x<t;x++){
		scanf("%s",guru[x].lCode);
		scanf("%s",guru[x].lName);
		scanf("%s",guru[x].lGender);
		scanf("%d",&guru[x].lStudent);
		for(int y = 0;y<*guru[x].lStudent;y++){
			scanf("%s", guru[x].murid[y].sCode);
			scanf("%s", guru[x].murid[y].sName);
			scanf("%s",guru[x].murid[y].sGender);
			scanf("%s",guru[x].murid[y].sFather);
			scanf("%s",guru[x].murid[y].sMother);
			scanf("%s", guru[x].murid[y].sSibling);
//			index++;
		}
	}
	scanf("%d",&k);
	printf("Kode Dosen: %s\n",guru[k-1].lCode);
	printf("Nama Dosen: %s\n",guru[k-1].lName);
	printf("Gender Dosen: %s\n",guru[k-1].lGender);
	printf("Jumlah Mahasiswa: %d\n",*guru[k-1].lStudent);
	int y = *guru[k-1].lStudent;
//	printf("y nya : %d\n", y);
//	for(int x = 0;x<k-1;x++){
//		sum += *guru[x].lStudent;
//	}
//	printf("sum nya : %d\n",sum);
	for(int u = 0; u<y;u++){
		printf("Kode Mahasiswa: %s\n",guru[k-1].murid[u].sCode);
		printf("Nama Mahasiswa: %s\n",guru[k-1].murid[u].sName);
		printf("Gender Mahasiswa: %s\n",guru[k-1].murid[u].sGender);
		printf("Nama Ayah: %s\n",guru[k-1].murid[u].sFather);
		printf("Nama Ibu: %s\n", guru[k-1].murid[u].sMother);
		printf("Jumlah Saudara Kandung: %s\n",guru[k-1].murid[u].sSibling);
	}

	return 0;
}
