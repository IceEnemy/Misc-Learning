#include <stdio.h>
#include <string.h>
int grade(int s){
	int fin;
	if(s>=90){
		fin = 1;
	}
	else if(s>=85){
		fin = 2;
	}
	else if(s>=80){
		fin = 3;
	}
	else if(s>=75){
		fin = 4;
	}
	else if(s>=70){
		fin = 5;
	}
	else if(s>=65){
		fin = 6;
	}
	else if(s>=50){
		fin = 7;
	}
	else{
		fin = 8;
	}
	return fin;
}
int valid(int score){
	if(score<0 && score>100){
		int inv = -1;
		return inv;
	}
	else if(score == 0){
		printf("Did the student submit the assignment? [Y] or [N]\n");
		char ans;
		scanf("%c",&ans);
		if(ans=='Y'){
			grade(score);
		}
		else if(ans=='N'){
			return 0;
		}
	}
	else{
		grade(score);
	}
}

int main()
{
	int nilai;
	scanf("%d",&nilai);
	getchar();
	int check = valid(nilai);
	if(check == 1){
		printf("A");
	}
	else if(check == 2){
		printf("A-");
	}
	else if(check == 3){
		printf("B+");
	}
	else if(check == 4){
		printf("B");
	}
	else if(check == 5){
		printf("B-");
	}
	else if(check == 6){
		printf("C");
	}
	else if(check == 7){
		printf("D");
	}
	else if(check == 8){
		printf("E");
	}
	else if(check == 0){
		printf("F");
	}
	else if(check == -1){
		printf("invalid score");
	}
}

