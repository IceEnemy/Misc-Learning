#include <stdio.h>
int main()
{
	int like,hate,sum=0,tempsum;
	int mode[1010];
	int zero=0,var=0;
	scanf("%d",&like);
	int kind1[like];
	for(int i=0;i<like;i++){
		scanf("%d",&kind1[i]);
	}
	scanf("%d",&hate);
	int kind2[hate];
	for(int i=0;i<hate;i++){
		scanf("%d",&kind2[i]);
	}
	for(int i=0;i<hate;i++){
		for(int j=0;j<like;j++){
			if(kind1[j]==kind2[i]){
				kind1[j]=0;
			}
		}
	}
	for(int i=0;i<like;i++){
		tempsum=0;
		if(kind1[i]!=0){
		for(int j=0;j<like;j++)
			if(kind1[i]==kind1[j]){
				tempsum++;
			}
		}
		else{
			zero++;
		}
		if(tempsum>=sum){
			sum=tempsum;
			mode[var]=kind1[i];
			var++;
		}
	}
	if(zero==like){
		printf("No Bird\n");
	}
	else{
	for(int i=0;i<var;i++){
		for(int j=i+1;j<var;j++){
			if (mode[i]==mode[j]){
				for(int k=j;k<var-1;k++){
					mode[k]=mode[k+1];
				}
				var--;
				j--;
			}
		}
		}
		for(int i=0;i<var;i++){
		printf("Bird %d\n",mode[i]);
	}
	}
	
	
 	return 0;
}

