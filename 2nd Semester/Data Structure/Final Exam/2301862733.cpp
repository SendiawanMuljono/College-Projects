#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
	long long int therm;
	char name[31];
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

Node *createNode(long long int therm, char name[]){
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->therm = therm;
	strcpy(temp->name,name);
	temp->height = 1;
	temp->left = temp->right = NULL; 
	
	return temp;
}

int getBalance(Node *root){
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
	
	if(balance<-1){//height right lbh pjg
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
	else if(balance>1){//height left lebih pjg
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

Node *push(Node *root, long long int therm, char name[]){
	if(!root){
		return createNode(therm,name);
	}
	if(therm<root->therm){
		root->left = push(root->left,therm,name);
	}
	else if(therm>root->therm){
		root->right = push(root->right,therm,name);
	}
	else{
		return root;
	}
	avl(root);
}

Node *predecessor(Node *root){
	Node *curr = root->left;
	while(curr->right){
		curr = curr->right;
	}
	return curr;
}

Node* remove(Node* root, long long int therm){
	if(!root){
		return root;
	}
	if(therm>root->therm){
		root->right = remove(root->right,therm);
	}
	else if(therm<root->therm){
		root->left = remove(root->left,therm);
	}
	else{
		if(!root->left||!root->right){
			Node *temp;
			if(root->left){
				temp = root->left;
			}
			else{
				temp = root->right;
			}
			//kalau NULL
			//berarti tidak punya anak sama sekali
			if(!temp){
				temp = root;
				root = NULL;
			}
			else{//punya 1 anak
				*root = *temp;
				//atau
//				root->key = temp->key;
//				root->left = temp->left;
//				root->right = temp->right;
			}
			free(temp);
		}
		else{
			Node *temp = predecessor(root);
			root->therm = temp->therm;
			root->left = remove(root->left,temp->therm);
		}
	}
	
	if(!root){
		return root;
	}
	avl(root);
}

Node *find(Node* root, long long int therm){
	if(!root){
		return NULL;
	}
	else{
		if(therm<root->therm){
			find(root->left,therm);
		}
		else if(therm>root->therm){
			find(root->right,therm);
		}
		else if(therm == root->therm){
			printf("%lld %s\n",root->therm,root->name);
			return root;
		}
	}
}

Node *find2(Node* root, long long int therm){
	if(!root){
		return NULL;
	}
	else{
		if((therm>root->left->therm) && (therm<root->right->therm)){
			printf("%lld %s\n",root->therm,root->name);
		}
		else if(therm<root->therm){
			find(root->left,therm);
		}
		else if(therm>root->therm){
			find(root->right,therm);
		}
	}
}

int count = 0;
void planetNum(Node *root){
	if(!root){
		return;
	}
    else{
        planetNum(root->left);
        count++;
        planetNum(root->right);
	}
}

int planet = 0;
void jml(Node *root, long long int therm){
	if(root==NULL){
		return;
	}
	else{
		jml(root->left,therm);
		if(root->therm>therm){
			planet++;
		}
		jml(root->right,therm);
	}
}

void inOrder(Node *root, int from, int to){
	if(root==NULL || from == to){
		return;
	}
	else{
		inOrder(root->left,from+1,to);
		printf("%d: %lld %s\n",from,root->therm,root->name);
		inOrder(root->right,from+1,to);
	}
}

int main(){
	int choose = 0;
	long long int therm;
	int t;
	scanf("%d",&t);
	for(int x = 0;x<t;x++){
		scanf("%d",&choose);
		if(choose == 1){
			char name[31];
			scanf("%lld %s",&therm,name);
			root = push(root,therm,name);
			jml(root,therm);
			printf("%d\n",planet);
			planet = 0;
		}
		else if(choose == 2){
			scanf("%lld", &therm);
			root = remove(root,therm);
			planetNum(root);
			printf("%d\n",count);
			count = 0;
		}
		else if(choose == 3){
			scanf("%lld", &therm);
			Node *temp = find(root,therm);
			if(!temp){
				root = find2(root,therm);
			}
		}
		else if(choose == 4){
			int from,to;
			scanf("%d %d",&from,&to);
			inOrder(root,from,to);
		}
	}
	
	return 0;
}

