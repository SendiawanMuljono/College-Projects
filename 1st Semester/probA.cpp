#include<stdio.h>

int main(){
	int t,up,down,jmlArray,index;
	int arr[100000];
	scanf("%d",&t);
	
	for(int x = 1;x<=t;x++){
		scanf("%d %d %d",&jmlArray, &up, &down);
		for(int y = 0;y<jmlArray;y++){
			scanf("%d", &arr[y]);
		}
		for(int i = 0;i<jmlArray-1;i++){
			index = i+1;
			if(arr[index]>arr[i]){
				up--;
			}
			else if(arr[index]<arr[i]){
				down--;
			}
			if(up <= 0 && down<=0){
				break;
			}
		}
		printf("Case #%d: %d\n",x,index+1);
	}
	
	
	return 0;
}
