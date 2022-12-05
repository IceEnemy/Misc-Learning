#include <stdio.h>
#include <string.h>

int main()
{
	int t;
	scanf("%d", &t);
	getchar();
	int num;
	char word[1010];
	
	for(int i = 1; i <= t; i++){
		scanf("%d", &num);
		getchar();
		scanf("%[^\n]", word);
		getchar();
		int length = strlen(word);
			
			for(int j = 0; j < length; j++)	{
				
				if(num == 0){
					if(word[j] == 'a'){
						printf("%%");
					}
					else if(word[j] == 'i'){
						printf("-");
					}
					else if(word[j] == 'u'){
						printf("+");
					}
					else if(word[j] == 'e'){
						printf("@");
					}
					else if(word[j] == 'o'){
						printf("#");
					}
					else if(word[j] == ' '){
						printf(" ");
					}
					else if(word[j] >= 'b' && word[j] <= 'w' && word[j] != 'i' && word[j] != 'u' && word[j] != 'e' && word[j] != 'o' ){
						printf("%c",word[j]+3);
					}else if(word[j] == 'x'){
						printf("a");
					}
					else if(word[j] == 'y'){
						printf("b");
					}
					else if(word[j] == 'z'){
						printf("c");
					}
					else printf("%c",word[j]);
					
				}				
				
				if(num == 1){
					if(word[j] == '%'){
						printf("a");
					}
					else if(word[j] == '-'){
						printf("i");
					}
					else if(word[j] == '+'){
						printf("u");
					}
					else if(word[j] == '@'){
						printf("e");
					}
					else if(word[j] == '#'){
						printf("o");
					}
					else if(word[j] == ' '){
						printf(" ");
					}
					else if(word[j] >= 'd' && word[j] <= 'z' ){
						printf("%c" , word[j]-3);
					}
					else if(word[j] == 'a'){
						printf("x");
					}
					else if(word[j] == 'b'){
						printf("y");
					}
					else if(word[j] == 'c'){
						printf("z");
					}
					else printf("%c",word[j]);
				}
			}	
		printf("\n");
	}
	
	
 	return 0;
}

