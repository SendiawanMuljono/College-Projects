#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct kopi{
	char nama[100];
	char type[100];
	int quan;
	int price;
	kopi *next, *prev;
}*head[2], *tail[2], *curr, *temp;

kopi *create(char nama[], char type[], int quan, int price){
	kopi *curr = (kopi*)malloc(sizeof(kopi));
	strcpy(curr->nama,nama);
	strcpy(curr->type,type);
	curr->quan = quan;
	curr->price = price;
	curr->next = curr->prev = NULL;
	return curr;
}

void push(int idx, char nama[], char type[], int quan, int price){
	curr = create(nama,type,quan,price);
	if(!head[idx]){
		head[idx] = tail[idx] = curr;
	}
	else{
		tail[idx]->next = curr;
		curr->prev = tail[idx];
		tail[idx] = curr;
	}
}

void popHead(int idx){
	if(head[idx]){
		if(head[idx] == tail[idx]){
			free(head[idx]);
			head[idx] = tail[idx] = NULL;
		}
		else{
			kopi *pndh = head[idx];
			head[idx] = head[idx]->next;
			free(pndh);
			head[idx]->prev = NULL;
		}
	}
}

void popTail(int idx){
	if(head[idx]){
		if(head[idx] == tail[idx]){
			free(head[idx]);
			head[idx] = tail[idx] = NULL;
		}
		else{
			kopi *pndh = tail[idx];
			tail[idx] = tail[idx]->prev;
			free(pndh);
			tail[idx]->next = NULL;
		}
	}
}

void pop(int pilih){
	int jml = 0;
	curr = head[1];
	while(curr){
		jml++;
		if(jml == pilih){
			if(curr == head[1]){
				popHead(1);
			}
			else if(curr == tail[1]){
				popTail(1);
			}
			else{
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
				free(curr);
			}
		}
		curr = curr->next;		
	}
}

void popAll(){
	temp = head[0];
	while(temp){
		curr = head[1];
		while(curr){
			if(strcmp(temp->nama,curr->nama)==0){
				curr->quan += temp->quan;
				break;
			}
			else{
				curr = curr->next;
			}
		}
		temp = temp->next;
		popHead(0);
	}
}

void view(int idx){
	int no = 0;
	printf("No.| Menu                                              | Type       | Quantity | Price             |\n");
	printf("----------------------------------------------------------------------------------------------------\n");
	curr = head[idx];
	while(curr){
		no++;
		printf("%-3d| %-49s | %10s | %8d |      %-8d     |\n",no,curr->nama,curr->type,curr->quan,curr->price);
		curr = curr->next;
	}
	printf("----------------------------------------------------------------------------------------------------\n");
}

void menu(int check, char user[]){
	printf("====================================================================================================\n");
	printf("                                        +++++  Brew Coffee Shop  +++++                              \n");
	printf("Welcome, Mr./Mrs. %s\n\n", user);
	printf("====================================================================================================\n");
	view(1);
	if(!head[0] && check == 0){
		printf("data is empty\n\n");
	}
	else if(head[0]){
		printf("\n\nyour order:\n");
		view(0);
	}
	if(check == 1){
		printf("1. Add item\n");
		printf("2. Remove item\n");
	}
	else{
		printf("1. Buy item\n");
		printf("2. Cancel item\n");
	}
	printf("3. Exit\n");
	printf("____________________________________________________________________________________________________\n");
}

int checkCustOrAdm(char user[]){
	int admin = 0;
	if(strlen(user)==5){
		for(int x = 0;x<5;x++){
			if(user[x] >= 'A' && user[x]<= 'Z'){
				user[x] += 32;
			}
		}
		if(user[0] == 'a' && user[1] == 'd' && user[2] == 'm' && user[3] =='i' && user[4]=='n'){
			admin = 1;
		}
	}
	if(user[0]>='a'&&user[0]<='z'){
		user[0]-=32;
	}
	if(admin == 1){
		return 1;
	}
	else{
		for(int x = 1;x<strlen(user);x++){
			if(user[x]>='A' && user[x]<='Z'){
				user[x]+=32;
			}
		}
		return 0;
	}
}

void findAdm(int num){
	int numb = 0;
	curr = head[1];
	while(curr){
		numb++;
		if(numb == num){
			break;
		}
		else{
			curr = curr->next;
		}
	}
}

int findCust(char nama[]){
	temp = head[0];
	int ada = 0;
	while(temp){
		if(strcmp(temp->nama,nama)==0){
			ada = 1;
			break;			
		}
		else{
			temp = temp->next;
		}
	}
	return ada;
}

void admin(int check, char user[]){
	int valid = 1;
	do{
		int action;
		menu(check,user);
		do{
			printf("Enter your action: ");
			scanf("%d", &action);getchar();
			if(action == 1){
				char item[100];
				do{
					printf("Insert item name: ");
					scanf(" %[^\n]", item);
					if(strlen(item)<5||strlen(item)>19){
						printf("input lenth of name between 5 and 19\n");
					}
				}while(strlen(item)<5||strlen(item)>19);
				char tipe[100];
				do{
					printf("Type of Coffee[yes/no]: ");
					scanf("%s",tipe);
				}while(strcmp(tipe, "yes") != 0 && strcmp(tipe, "no") !=0);
				int quantity = 0;
				do{
					printf("Insert the quantity of the item: ");
					scanf("%d", &quantity);getchar();
					if(quantity<2||quantity>99){
						printf("please insert quantity between 2 - 99\n");
					}
				}while(quantity<2||quantity>99);
				int price = 0;
				do{
					printf("Insert the price of the item: ");
					scanf("%d",&price);
					if(price<10001||price>99999){
						printf("please insert price between 10.001 - 99.999\n");
					}
				}while(price<10001 || price>99999);
				if(strcmp(tipe,"yes") == 0){
					push(1, item, "Coffee", quantity, price);
				}
				else{
					push(1, item, "Non-coffee", quantity, price);
				}
			}
			else if(action == 2){
				if(!head[1]){
					printf("Data tidak ditemukan\n");
				}
				else{
					int jml = 0;
					curr = head[1];
					while(curr){
						jml++;
						curr = curr->next;
					}
					int pilih = 0;
					do{
		 				printf("Which product do you want to remove [1-%d]: ",jml);
		 				scanf("%d",&pilih);
		 				if(pilih<1||pilih>jml){
							printf("select the data between 1 - %d\n", jml);
						}
					}while(pilih<1||pilih>jml);
					pop(pilih);
				}
			}
			else if(action == 3){
				valid = 0;
			}
		}while(action<1||action>3);
	}while(valid == 1);
}

void customer(int check, char user[]){
	int valid = 1;
	do{
		int action;
		menu(check,user);
		do{
			printf("Enter your action: ");
			scanf("%d", &action);getchar();
			if(action<1 || action>3){
				printf("please insert number between 1 - 3\n");
			}
			else if(action == 1){
				printf("\n");
				view(1);
				int num = 0;
				do{
					printf("choose your menu [1-3]: ");
					scanf("%d", &num);getchar();
					if(num<1||num>3){
						printf("insert valid number\n");
					}
				}while(num<1||num>3);
				findAdm(num);
				int q = 0;
				do{
					printf("enter the quantity [1 - %d]: ",curr->quan);
					scanf("%d", &q);getchar();
					if(q<1||q>curr->quan){
						printf("insert quantity number between 1 - %d\n",curr->quan);
					}
				}while(q<1||q>curr->quan);
				printf("success\n");
				curr->quan-=q;
				int harga = curr->price*q;
				int ada = findCust(curr->nama);
				if(ada == 1){
					temp->quan += q;
					temp->price += harga;
				}
				else{
					push(0,curr->nama,curr->type,q,harga);
				}
			}
			else if(action == 2){
				if(!head[0]){
					printf("no data\n");
				}
				else{
					//Cancel order, berarti quantity tokonya tdk jd berkurang
					popAll();
				}
			}
			else if(action == 3){
				valid = 0;
			}
		}while(action<1||action>3);
	}while(valid == 1);
}

int main(){
	char user[100];
	do{
		printf("enter your name: ");
		scanf(" %[^\n]", user);
	}while(strlen(user)<4);
	push(1, "Americano", "Coffee", 24, 19000);
	push(1, "Chocolate Baked", "Non-coffee", 15, 24000);
	push(1, "Alberto", "Coffee", 7, 44000);
	int check = checkCustOrAdm(user);
	if(check == 1){
		//Menu kopi ada di idx 1
		admin(check, user);
	}
	else{
		//Orderan customer ada di idx 0
		customer(check,user);
	}
	
	return 0;
}
