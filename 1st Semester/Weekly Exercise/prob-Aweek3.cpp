#include<stdio.h>

int main(){
	int i = 0, z =0;
	char str[10001];
	
	scanf("%[^\n]", str);
	
	for(z = 0;str[z]!='\0';z++);
	while(str[i]!='\0'){
		if(str[i]>90){
			str[i] -= 32;
		}
		i++;
	}
	for(int x = 0;x<z;x++){
		if(str[x] == 'I'){
			str[x] = '1';	
		}
		else if (str[x] == 'R'){
			str[x] = '2';	
		}
		else if (str[x] == 'E'){
			str[x] = '3';	
		}
		else if (str[x] == 'A'){
			str[x] = '4';	
		}
		else if (str[x] == 'S'){
			str[x] = '5';	
		}
		else if (str[x] == 'G'){
			str[x] = '6';	
		}
		else if (str[x] == 'T'){
			str[x] = '7';	
		}
		else if(str[x] == 'B'){
			str[x] = '8';	
		}
		else if(str[x] == 'P'){
			str[x] = '9';	
		}
		else if(str[x] == 'O'){
			str[x] = '0';	
		}
	}
	printf("%s\n", str);
	
	return 0;
}
