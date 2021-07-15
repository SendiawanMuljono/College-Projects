#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
	char name[101];
	int priority;
	data *next,*prev;
}*head = NULL, *tail = NULL, *curr = NULL;

data* create(char name[], int prior){
	data *curr = (data*)malloc(sizeof(data));
	strcpy(curr->name,name);
	curr->priority = prior;
	curr->next = curr->prev = NULL;
	return curr;
}

void pushTail(char name[],int prior){
	curr = create(name,prior);
	if(!head){
		head = tail = curr;
	}
	else{
		curr->prev = tail;
		tail->next = curr;
		tail = curr;
	}
}

void pushHead(char name[],int prior){
	curr = create(name,prior);
	if(!head){
		head = tail = curr;
	}
	else{
		curr->next = head;
		head->prev = curr;
		head = curr;
	}
}

void pushPrior(char name[], int prior){
	curr = create(name,prior); 
	if(!head){
		pushHead(name,prior);
	}
	else if(curr->priority<head->priority){
		pushHead(name,prior);
	}
	else if(curr->priority>tail->priority){
		pushTail(name,prior);
	}
	else if(curr->priority==tail->priority){
		pushTail(name,prior);
	}
	else{
		//di tengah2
		data *temp = head;
		while(temp){
			temp = temp->next;
			if(temp->priority>curr->priority){
				break;
			}
		}
		curr->next = temp;
		curr->prev = temp->prev;
		temp->prev->next = curr;
		temp->prev = curr;
	}
}

void popHead(){
	if(head){
		if(head == tail){
			free(head);
			head = tail = NULL;
		}
		else{
			curr = head;
			head = head->next;
			free(curr);
			head->prev = NULL;
		} 
	}
}

void popTail(){
	if(head){
		if(head == tail){
			free(tail);
			tail = head = NULL;
		}
		else{
			curr = tail;
			free(curr);
			tail = tail->prev;
			tail->next = NULL;
		}
	}
}

void rmvAll(){
	while(head){
		popHead();
	}
}

void remove(char name[]){
	int valid = 0;
	if(strcmp(tail->name,name)==0){
		popTail();
		valid = 1;
	}
	else if(strcmp(head->name,name)==0){
		popHead();
		valid = 1;
	}
	else{
		curr = head;
		while(curr){
			if(strcmp(curr->name,name)==0){
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
				free(curr);
				valid = 1;
				break;
			}
			curr = curr->next;
		}
		
	}	
	if(valid == 0){
		printf("wish not found...\n\n");
	}
}

void view(){
	if(!head){
		printf("Wish list is empty...\n\n");
	}
	else{
		int num = 1;
		curr = head;
		while(curr){
			printf("%.2d. %s #%d\n",num, curr->name, curr->priority);
			curr = curr->next;
			num++;
		}
		printf("\n");
	}
}

void menu(){
	printf("1. Add wish\n");
	printf("2. View wish list\n");
	printf("3. Remove wish\n");
	printf("4. Exit\n");
	printf("Please choose: ");
}


int main(){
	char name[101];
	int choose = 0,priority = 0;
	do{
		menu();
		scanf("%d",&choose);
		getchar();
		printf("\n");
		if(choose == 1){
			do{
				printf("Input wish name [2..100]: ");
				scanf(" %[^\n]",name);
			}while(strlen(name)<2||strlen(name)>100);
			do{
				printf("Input wish priority [1..10]: ");
				scanf("%d",&priority);
				getchar();
			}while(priority<1||priority>10);
			pushPrior(name,priority);
			printf("\n");
			choose = 0;
		}
		else if(choose == 2){
			view();
			choose = 0;
		}
		else if(choose == 3){
			do{
				printf("Input wish name [2..100]: ");
				scanf(" %[^\n]",name);
			}while(strlen(name)<2||strlen(name)>100);
			if(!head){
				printf("wish not found...\n\n");
			}
			else{
				remove(name);
			}
			choose = 0;
		}
		else if(choose == 4){
			rmvAll();
		}
	}while(choose<1||choose>4);
	
	
	return 0;
}
