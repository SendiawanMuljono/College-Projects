#include<stdio.h>

int main(){
   	int t,n, a[20000], count, c=0, val;
   	long long int M, test;
   	scanf("%d",&n);
   	for(int o = 0;o<n;o++){
		scanf ("%d",&a[o]);
    }
   	scanf ("%d",&t);
   	for (int x =1;x<=t;x++){
		count = 0; c=0;test=0;val=0;
  	  	scanf ("%lld",&M);
        for (int i = 0; i<n;i++){
            count=0; test=0;
	    	if(a[i]>M){
	    		val++;
	    	}
            test+=a[i];
            if(n-i-c<=0){
                break;
            }
            for (int j = i+1;j<n;j++){
                test+=a[j];
                if (test<=M){
                    count++;
                }
                else{
                    break;
                }
            }
            if(count>c){
                c = count;
            }
        }  
		if(val == n){
			printf("Case #%d: -1\n",x);
		} 
		else{
        	printf ("Case #%d: %d\n",x,c+1);   
		}    
    }
    return 0;
}

