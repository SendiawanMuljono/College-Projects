#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data
{
	char value[100];
	struct data *next;
};

struct data *hashTables[31];

int hash(const char *str) 
{
	int length = strlen(str);
	int base = 11;
	int MOD = 31;
	int key = 0;
	for(int i = 0; i < length; i++) 
	{
		key = (key * base) + (str[i] - 'a' + 1);
		key = key % MOD;
	}
	return (key * base) % MOD;
}

void chaining(int idx,const char *str)
{
	struct data *newData = (struct data *) malloc(sizeof(struct data));
	strcpy(newData->value, str);
	newData->next = NULL;
	//INSERT YOUR CODE HERE, Insert Code to Insert Data into Hashtable with chaining
	if(!hashTables[idx]){
		hashTables[idx] = newData;
	}
	else{
		struct data *curr = hashTables[idx];
		while(curr->next){
			curr = curr->next;
		}
		curr->next = newData;
	}
}

void viewAll()
{
	//INSERT YOUR CODE HERE, View Data if the index have Data
	for(int x = 0;x<31;x++){
		struct data *curr = hashTables[x];
		if(hashTables[x]){
			printf("Index %d: ",x);
			while(curr){
				printf("%s",curr->value);
				curr = curr->next;
				if(curr){
					printf(" -> ");
				}
			}
			printf("\n");
		}
	}
}

void popAll()
{
	//INSERT YOUR CODE HERE, Pop All the hashtable
	int index = 0;
	while(index<31){
		hashTables[index] = NULL;
		index++;
	}
}

void init()
{
	for(int i = 0 ; i < 31 ; i++)
	{
		hashTables[i] = NULL;
	}
}

int main()
{
	char data[][100] = 
	{
		"roti",
		"keju",
		"coklat",
		"durian",
		"nasi",
		"buncis",
		"ayam",
		"air",
		"mie",
		"tahu",
		"tempe",
		"susu",
		"sapi",
		"telur",
		"biskuit",
		"wortel",
		"steak",
		"kentang",
		"apel",
		"melon",
		"ikan"
	};
	
	init();
	
	int count = sizeof(data) / sizeof(data[0]);
	
	for(int i = 0 ; i < count ; i++)
	{
		int idx = hash(data[i]);
		chaining(idx,data[i]);
	}
	
	viewAll();
	popAll();
	return 0;
}

