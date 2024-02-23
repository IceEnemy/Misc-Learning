#include <stdio.h>
int main()
{
    int test,most=0;
    
    scanf("%d",&test);
    int num[test];
    
    for(int i=0;i<test;i++){
        scanf("%d",&num[i]);
        int mode=0;
        
        for(int j=0;j<test;j++){
        	
            if(num[i]==num[j]){
                mode++;
            }
        }
        
        if(mode>most && mode != 0){
            most = mode;
        }
    }
    printf("%d\n",most);
     return 0;
}
