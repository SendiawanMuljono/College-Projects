#include<stdio.h>

struct data{
	char name[101],nim[10],age[4],pos[7],pBirth[101],dBirth[101],hSchool[101],sibling[4],height[5],bank[10];
}mahasiswa;


int main(){
	int t;
	scanf("%d", &t);
	for(int x = 1;x<=t;x++){
		scanf(" %[^\n]", mahasiswa.name);
		scanf("%s", mahasiswa.nim);
		scanf("%s", mahasiswa.age);
		scanf("%s", mahasiswa.pos);
		scanf(" %[^\n]", mahasiswa.pBirth);
		scanf("%s", mahasiswa.dBirth);
		scanf(" %[^\n]", mahasiswa.hSchool);
		scanf("%s", mahasiswa.sibling);
		scanf("%s", mahasiswa.height);
		scanf("%s", mahasiswa.bank);
		printf("Mahasiswa ke-%d:\n",x);
		printf("Nama: %s\n",mahasiswa.name);
		printf("NIM: %s\n",mahasiswa.nim);
		printf("Umur: %s\n",mahasiswa.age);
		printf("Kode Pos: %s\n",mahasiswa.pos);
		printf("Tempat Lahir: %s\n",mahasiswa.pBirth);
		printf("Tanggal Lahir: %s\n",mahasiswa.dBirth);
		printf("Almamater SMA: %s\n",mahasiswa.hSchool);
		printf("Jumlah Saudara Kandung: %s\n",mahasiswa.sibling);
		printf("Tinggi Badan: %s\n",mahasiswa.height);
		printf("NOMOR REKENING: %s\n",mahasiswa.bank);
	}

	return 0;
}
