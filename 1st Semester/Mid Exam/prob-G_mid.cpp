#include<stdio.h>


int main(){
	int arr2[1000001]={},arr3[1000001]={};
	int t;
	int a,b,i = 2,z=3,k = 1000000007;
	scanf("%d", &t);
	arr2[0] = 1;
	arr2[1] = 2;
	for(int j = 2;j<=1000000;j++){
		i = (i*2)%k;
		arr2[j] = i;
	}
	arr3[0] = 1;
	arr3[1] = 3;
	for(int h = 2;h<=1000000;h++){
		z = (z*3)%k;
		arr3[h] = z;
	}
	for(int x = 0;x<t;x++){
		scanf("%d %d", &a, &b);
		int y = 0;
		y = (arr2[a]*arr3[b])%k;
		printf("%d\n", y);
	}
	
	
	return 0;
}
