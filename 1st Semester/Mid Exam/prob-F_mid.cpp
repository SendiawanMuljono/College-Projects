#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
	char string[100],p,k,l,templ,tempp;
	int t;
	scanf("%d",&t);
	for(int x =1;x<=t;x++){
		scanf("%s", string);
		int total = 0;
		for(int y = 0;y<strlen(string);y++){
			if(string[y] == '1'&&string[y-1] != '-'){
				templ = y;
			}
			else if(string[y]=='('){
				tempp = y;
			}
//			else{
//			}
//			if(string[y] == '1'&&string[y-1] != '-'){
//				l = pow(2,strlen(string) - 3 - y-1);
//			}
//			else if(string[y]=='('){
//				p = pow(2,strlen(string)-3-y-1);
//			}
		}
		if(templ<tempp){
			l = pow(2,strlen(string) - 3 - templ-1);
			p = pow(2,strlen(string)-3-tempp-1);
			total = l-p;
			printf("Case #%d: %d\n",x,total);
		}
		else{
			l = pow(2,strlen(string)- templ-1);
			p = pow(2,strlen(string)-3-tempp-1);
			total = l-p;
			printf("Case #%d: %d\n",x,total);
		}
	}
	
	return 0;
}
