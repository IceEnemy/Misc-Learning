#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    while(1){
    	char input[100] = {NULL};
        scanf("%[^\n]",input);
        getchar();
        if(strcmp(input,"done") == 0) break;
//        char *str = strstr(input,"Mr. ");
        if(strstr(input,"Mr. ") != NULL && strcmp(strstr(input,"Mr. "),input) == 0){
            printf("Email Valid\n");
        }
        else{
            printf("Invalid Email\n");
        }
    }
    return 0;
}


