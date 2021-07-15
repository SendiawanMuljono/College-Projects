#include<stdio.h>

int main(){
	int t,len,wkwk = 0,n=0;
	char string[201];
	scanf("%d",&t);
	for(int x = 1;x<=t;x++){
		scanf("%d", &len);
		scanf(" %[^\n]", string);
		for(int y = 0;y<len;y++){
			if(string[y] == ' ' &&wkwk == 0){
				string[y] = '#';
				wkwk = 1;
			}
			if(string[y]!=' '&&wkwk == 1){
				string[y] = '#';
			}
			if(string[y]==' '&&wkwk==1){
				string[y] = ' ';
				wkwk = 0;
			}
		}
		printf("Case #%d: ",x);
		for(int z = 0;z<len;z++){
			if(string[z]!='#'){
				printf("%c",string[z]);
			}
		}
		printf("\n");wkwk=0;
	}	
	return 0;
}

//2
//38
//Hi asd Bibi, JnYS how IqJ12 are a you?
//42
//My wJs space huJDSk key 123 is aSd broken.
