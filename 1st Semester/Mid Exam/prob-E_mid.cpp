#include<stdio.h>
#include<math.h>

int main(){
	int t, num,arr[100] = {0}, y = 0,z=0, arr_prime[100] = {0},count = 1;
	scanf("%d", &t);
	for(int x = 1;x<=t;x++){
		scanf("%d", &num);
		for(int j = 1;j<=num;j++){
			count = count*j;
		}
			printf("%d\n",count);
		for(int i = 2;i<=count/2;i++){
			if(count % i == 0){
				arr[y] = i;
				y++;
			}
		}
		int h = 0;
		while(arr[h]!=0){
			if(arr[h] % 2 == 0 && arr[h] != 2||arr[h]%3 == 0&&arr[h]!=3||arr[h]%5==0&&arr[h]!=5||arr[h]%7==0&&arr[h]!=7){
			}
			else{
				arr_prime[z] = arr[h];
				z++;
			}
			h++;
		}
		int g = 0;
		while(arr_prime[g]!=0){
		printf("%d\n",arr_prime[g]);g++;
		}
		int w =0;
		while(arr_prime[w]!=0){
			arr_prime[w] = 0;
			w++;
		}
		w = 0;
		while(arr[w]!=0){
			arr[w] = 0;w++;
		}
		y=0;z=0;count = 1;
	}
	
	return 0;
}
