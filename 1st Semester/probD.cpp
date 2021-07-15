#include <stdio.h>

int main () {
	int t,d=27, m=6, y=2015, weekday;
	scanf("%d",&t);
	for(int x = 1;x<=t;x++){
		scanf("%d/%d/%d",&d,&m,&y);
		weekday = (d+=m<3?y--:y-2,23*m/9+d+4+y/4-y/100+y/400)%7;
		printf("Case #%d: ",x);
		if(weekday == 0){
			printf("Sunday\n");
		}
		else if(weekday == 1){
			printf("Monday\n");
		}
		else if(weekday == 2){
			printf("Tuesday\n");
		}
		else if(weekday == 3){
			printf("Wednesday\n");
		}
		else if(weekday == 4){
			printf("Thursday\n");
		}
		else if(weekday == 5){
			printf("Friday\n");
		}
		else if(weekday == 6){
			printf("Saturday\n");
		}
	}

	return 0;
}
