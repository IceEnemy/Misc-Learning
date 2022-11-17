#include<stdio.h>

int main (){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int length;
        int breath;
        scanf("%d %d",&length, &breath);
        getchar();
        char arr[length];
        scanf("%[^\n]",arr);
        if (breath>=length)
        {
            printf("Case #%d: Alive\n",i+1);
            continue;
        }
        int count = 0;
        int die = 0;
        int temp2;
        // first to up
        for(int j=0;j<length;j++)
        {
            if (arr[j] == '0')
            {
                count ++;
                if (count == breath)
                {
                    die = 1; // same shit but ini beginning 
                    break;
                }
            }
            
            else if (arr[j] == '1' && die == 0)
            {
            	temp2 = j; // ini kalo udh naik tangga breath reset 0 tho u can just iniate again below 
                count = 0;
                break;
            }
        }
        
        //1 exit 
        int temp;
        for(int k=length-1;k>=0;k--)
        {
            if (arr[k] == '1')
            {
            	if(k != temp2){
	                temp = k; // no need incre/decrement
	                break;
	            }
	            else{ // biar tangga ga pake yg sama 
	            	die = 1;
	            	break;
				}
            }
        }
        // count =0;
        for (int o=temp;o<length;o++)
        {
            if (arr[o] == '0') // count 0 jika lbh dr breath lngsng mati
            {
                count ++;
                if (count == breath)
                {
                    die = 1;
                    break;
                }
            }
        }
        if (die == 1)    
        {
            printf("Case #%d: Dead\n",i+1);
        }
        else printf("Case #%d: Alive\n",i+1);
    }
    return 0;
}
