#include<stdio.h>

int main(){
   	int t,n, a[20000], count, c=0, val;
   	long long int M, test;
   	scanf ("%d",&t);
   	for (int x =1;x<=t;x++){
		count = 0; c=0;test=0;val=0;
  	  	scanf ("%d %lld",&n,&M);
   		for(int o = 0;o<n;o++){
			scanf ("%d",&a[o]);
    		if(a[o]>M){
    		val++;
    		}
    	}
//n adalah panjang array
//M adalah batas
      	if (val == n){
          	printf ("Case #%d: -1\n",x);
     	}
     	else{
          	for (int i = 0; i<n;i++){
              	count=0; test=0;
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
              	if (count>c){
                 	c = count;
              	}
          	}       
            printf ("Case #%d: %d\n",x,c+1);
       }
    }
    return 0;
}
