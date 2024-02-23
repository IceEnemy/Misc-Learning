#include <stdio.h>
int main()
{
    int test,start,flip;
    scanf("%d",&test);

    for(int i=1;i<=test;i++){
        int total,page;
        flip=0;
        scanf("%d %d",&total,&page);
        if(page>total/2 && total%2==0){
            while(page<total){
                total-=2;
                flip++;
            }
        }
        else if(page>total/2 && total%2==1){
            if(page>=total-1){
            	flip=0;
			}
			else{
				flip=(total-page)/2;
			}
        }
        else{
            int current=1;
            while(current<page){
                current+=2;
                flip++;
            }
        }
        printf("Case #%d: %d\n",i,flip);
    }
     return 0;
}
