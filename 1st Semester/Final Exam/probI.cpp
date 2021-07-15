#include<stdio.h>

int main(){
	int t;
	long long int n,x,a,b,c;
	long long int pembilang=0,penyebut=0;
	scanf("%d",&t);
	for(int y = 1;y<=t;y++){
		pembilang = 0;penyebut = 0;
		scanf("%lld %lld",&n,&x);
		if(n==1){
			pembilang = x;
			penyebut = 1;
		}
		else if(n==2){
			pembilang = x*x + 1;
			penyebut = x;
		}
		else if(n == 3){
			pembilang = x*x*x + 2*x;
			penyebut = x*x +1;
		}
		else if(n == 4){
			a = x*x*x;
			b = a*x;
			pembilang = b + 3*x*x + 1;
			penyebut = x*x*x + 2*x;
		}
		else{
			a = x*x*x;
			b = a*x*x;
			c = a*x;
			pembilang = b + 4*x*x*x + 3*x;
			penyebut = c + 3*x*x + 1;
		}
		printf("Case #%d: %lld/%lld\n",y,pembilang,penyebut);
	}
	return 0;
}
