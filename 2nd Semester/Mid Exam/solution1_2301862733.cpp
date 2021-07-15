#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//m = table size
int m = 23;

struct tnode{
	char value[10];
	int step;
}*ND[25];

int hashing(char value[10]){ 
	//complete the code to do hashing using division hashing function
	//add all the character ASCII in the string
	int key = 0;
	for(int x = 0;x<strlen(value);x++){
		key+=value[x];
	}
	key%=m;
		
	return key;
}

struct tnode *newData(char value[10]){ 
	//complete the code to create a new tnode name ND
	struct tnode *ND = (tnode*)malloc(sizeof(tnode));
	strcpy(ND->value,value);
	
	return ND;
}

void insert(char value[10]){ 
	struct tnode *N_Data = newData(value);
	int key = hashing(value);
	
	//complete the code to insert new data to hash table. If there is any collision, use linear probing to solve it and show ‘TABLE IS FULL!!!’ when the hash table is full or the data cannot be insert to the table.
	if(!ND[key]){
		ND[key] = N_Data;
	}	
	else{
		int full = 0;
		for(int i = 0;i<=key;i++){
			if(!ND[i]){
				break;
			}
			else{
				full++;
			}
		}
		int langkah = 0, inserted = 0;
		for(int x = key+1;x<m;x++){
			langkah++;
			if(!ND[x]){
				inserted = 1;
				ND[x] = N_Data;
				ND[x]->step = langkah;
				break;
			}
		}
		full+=langkah;
		if((full == m) || (inserted == 0)){
			printf("TABLE IS FULL!!!\n");
		}
	}
}

void view(){
	for(int i=0;i<m;i++){
		if(ND[i]) printf("[%d]\t%s (%d step(s))\n", i, ND[i]->value, ND[i]->step+1);
		else printf("[%d]\tNULL\n", i);
	}
}

int main(){
	for(int i=0;i<m;i++){
		ND[i] = NULL;
	}

	insert("AAAAA");
	insert("BBBBB");
	insert("CCCCC");
	insert("AAABB");
	insert("BABAA");
	insert("BAABA");
	insert("BBAAA");
	insert("ABBAA");
	
	
	view();
	return 0;
}
