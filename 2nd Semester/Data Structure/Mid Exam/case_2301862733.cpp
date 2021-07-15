#include<stdio.h>
#include<stdlib.h>

struct data{
	int cave;
	int gold;
	int level;
	data *left,*right;
}*root = NULL;

data *create(int cave, int gold, int level){
	data *curr = (data*)malloc(sizeof(data));
	curr->cave = cave;
	curr->gold = gold;
	curr->level = level;
	curr->left = curr->right = NULL;
	
	return curr;
}

data *push(data *root, int cave, int gold, int level){
	if(!root){
		return create(cave,gold,level);
	}
	else{
		if(cave < root->cave){
			root->left = push(root->left,cave,gold,level+1);
		}
		else if(cave> root->cave){
			root->right = push(root->right,cave,gold,level+1);
		}
	}
		
	return root;
}

data *check(data *root, int cave, int gold){
	if(!root){
		return NULL;
	}
	else{
		if(root->cave == cave){
			root->gold+=gold;
			return root;
		}
		else if(cave < root->cave){
			check(root->left,cave,gold);
		}
		else if(cave > root->cave){
			check(root->right,cave,gold);
		}
	}
}

void display(data *root){
	if(!root){
		return;
	}
	else{
		display(root->left);
		printf(" >> Cave %-3d  (depth %-3d), total gold production: %d\n",root->cave,root->level,root->gold);
		display(root->right);
	}
}

int hgt(data *root){
	int max = 1;
	if(root){
		int kiri = hgt(root->left);
		int kanan = hgt(root->right);
		if(kiri>kanan){
			max+=kiri;
			return max;
		}
		else{
			max+=kanan;
			return max;
		}
	}
}

int count = 0;
void miningReport(data *root,int lvl){
	if(!root){
		return;
	}
	if(root->level == lvl){
		count += root->gold;
		return;
	}
	miningReport(root->left,lvl);
	miningReport(root->right,lvl);
}

void rmvAll(data *root){
	if(!root){
		return;
	}
	rmvAll(root->right);
	rmvAll(root->left);
	free(root);
}

int main(){
	int choose = 0;
	do{
		printf("\n");
		printf(" Hov Mining Simulator\n");
	 	printf(" ====================\n");
		printf(" [1] Insert Mining Data\n");
	 	printf(" [2] Display All Cave Data\n");
	 	printf(" [3] Display Mining Reports\n");
	 	printf(" [4] Exit\n");
	 	printf(" >> ");
		scanf("%d",&choose);
		getchar();
		system("cls");
		if(choose == 1){
			int cave,gold;
			do{
				printf("\n");
				printf(" Input cave index [1-999]     : ");
				scanf("%d",&cave);
				getchar();
			}while(cave<1||cave>999);
			do{
	 			printf(" Input gold production [1-100]: ");
				scanf("%d",&gold);
				getchar();
			}while(gold<1||gold>100);
			printf("\n");
			data *root2 = check(root, cave, gold);
			int depth = 1;
			if(root2){
				printf(" Cave index already exists.\n");
				printf(" New total gold production for Cave %d is %d.\n\n\n",cave,root2->gold);
				printf(" Press any key to continue...");getchar();
			}
			else{
				printf(" New cave index detected.\n");
				printf(" Total gold production for Cave %d is %d.\n\n\n",cave, gold);
				printf(" Press any key to continue...");getchar();
				root = push(root,cave,gold,depth);
			}
			system("cls");
			choose = 0;
		}
		else if(choose == 2){
			if(!root){
				printf("\n Cave data is empty, nothing to display.\n\n");
				printf(" Press any key to continue...");getchar();
			}
			else{
				printf("\n");
				display(root);
				printf("\n Press any key to continue...");getchar();
			}
			system("cls");
			choose = 0;
		}
		else if(choose == 3){
			if(!root){
				printf("\n Cave data is empty, nothing to report.\n\n");
				printf(" Press any key to continue...");getchar();
			}
			else{
				int maks = hgt(root);
				printf("\n");
				for(int x = 1;x<=maks;x++){
					count = 0;
					miningReport(root,x);
					printf(" >> Total gold production for depth %-3d is %d\n",x,count);
				}
				printf("\n Press any key to continue...");getchar();
			}
			system("cls");
			choose = 0;
		}
		else if (choose == 4){
			rmvAll(root);
			printf("\n All data has been removed from memory.\n");
			printf(" Thank you for playing, see you again...\n");
		}
	}while(choose<1||choose>4);
	
	return 0;
}
