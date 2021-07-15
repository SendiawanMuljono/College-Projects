#include<stdio.h>
#include<stdlib.h>

struct Node{
	int num;
	int height;
	Node *left,*right;
}*root;

int max(int a, int b){
	if(a>b){
		return a;
	}
	return b;
}

int getHeight(Node *temp){
	if(!temp){
		return 0;
	}
	return temp->height;
}

int setNewHeight(Node *root){
	return max(getHeight(root->left),getHeight(root->right))+1;
}

Node *createNode(int num){
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->num = num;
	temp->height = 1;
	temp->left = temp->right = NULL; 
	
	return temp;
}

int getBalance(Node *root){
	//Height left - height right
//	if(!root){
//		return 0;
//	}
	return getHeight(root->left) - getHeight(root->right);
}

Node *leftRotate(Node *root){
	Node *temp = root->right;
	Node *temp2 = temp->left;
	temp->left = root;
	root->right = temp2;
	
	root->height = setNewHeight(root);
	temp->height = setNewHeight(temp);
	
	return temp;
}

Node *rightRotate(Node *root){
	Node *temp = root->left;
	Node *temp2 = temp->right;
	
	temp->right = root;
	root->left = temp2;
	
	root->height = setNewHeight(root);
	temp->height = setNewHeight(temp);
	
	return temp;
}

Node *avl(Node *root){
	root->height = setNewHeight(root);
	int balance = getBalance(root);
	
	if(balance<-1){
		int childBalance = getBalance(root->right);
		if(childBalance<=0){
			//RR
			return leftRotate(root);
		}
		else{
			//RL
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
		
	}
	else if(balance>1){
		int childBalance = getBalance(root->left);
		if(childBalance>=0){
			//LL
			return rightRotate(root);
		}
		else{
			//LR
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
	}
	
	return root;
}

Node *push(Node *root, int num){
	if(!root){
		return createNode(num);
	}
	if(num<root->num){
		root->left = push(root->left,num);
	}
	else if(num>root->num){
		root->right = push(root->right,num);
	}
	else{
		return root;
	}
	avl(root);
}

Node *successor(Node *root){
	Node *curr = root->right;
	while(curr->left){
		curr = curr->left;
	}
	return curr;
}

Node *remove(Node *root, int num){
	if(!root){
		return NULL;
	}
	else{
		if(num < root->num){
			root->left = remove(root->left,num);
		}
		else if(num> root->num){
			root->right = remove(root->right,num);
		}
		else{
			//Found
			if(root->right&&root->left){
				//2 anak
				Node *temp = successor(root);
				root->num = temp->num;
				root->left = remove(root->left,num);
			}
			else{
				Node *temp;
				if(root->right){
					temp = root->right;
				}
				else{
					temp = root->left;
				}
				//1 anak
				if(temp){
					return temp;
				}
				else{//0 anak
					free(root);
					return NULL;
				}
			}
		}
		avl(root);
	}
}

int step = 0;
Node *find(Node *root, int num){
	step++;
	if(root){
		if(num < root->num){
			root->left = find(root->left,num);
		}
		else if(num> root->num){
			root->right = find(root->right,num);
		}
		else{
			printf("Need %d step(s) to find the number.\n\n",step);
		}
	}
	else{
		printf("Number is not found...\n\n");
	}
	
	return root;
}

void rmvAll(Node *root){
	if(!root){
		return;
	}
	rmvAll(root->right);
	rmvAll(root->left);
	free(root);
}

int main(){
	int choose = 0, num = 0;
	do{
		printf("Menu\n");
		printf("=================\n");
		printf("1. Add Number\n");
		printf("2. Delete Number\n");
		printf("3. Find Number\n");
		printf("4. Exit\n\n");
		do{
			printf("Menu number [1..4]: ");
			scanf("%d",&choose);getchar();
			printf("\n");
		}while(choose<1||choose>4);
		if(choose == 1){
			do{
				printf("Input number [1 - 100.000]: ");
				scanf("%d", &num);getchar();
			}while(num<1||num>100000);
			root = push(root,num);
			printf("Done to insert number %d...\n\n",num);
			choose = 0;
		}
		else if(choose == 2){
			do{
				printf("Input number [1 - 100.000]: ");
				scanf("%d", &num);getchar();
			}while(num<1||num>100000);
			root = remove(root,num);
			printf("Done to delete number %d...\n\n",num);
			choose = 0;
		}
		else if(choose == 3){
			do{
				printf("Input number [1 - 100.000]: ");
				scanf("%d", &num);getchar();
			}while(num<1||num>100000);
			step = 0;
			root = find(root,num);
			choose = 0;
		}
		else if(choose == 4){
			rmvAll(root);
			root = NULL;
		}
	}while(choose<1||choose>4);
	
	return 0;
}
