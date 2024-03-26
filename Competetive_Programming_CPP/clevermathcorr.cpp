#include <stdio.h>
#include <string.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		char l[10],r[10];
		char l2[10],r2[10];
		for(int t=0;t<10;t++){
			l[t]='0';
			r[t]='0';
		}
		int len1,len2;
		int check=0;
		scanf("%s %s",&l,&r);
		if(strlen(l)>strlen(r)){
			len1=strlen(l);
			len2=strlen(r);
			for(int ri=len2;ri<len1;ri++){
				r[ri]='0';
			}
			for(int x=0;x<len1;x++){
				r2[x]=r[x];
				l2[x]=l[x];
			}
		}
		else if(strlen(l)<strlen(r)){
			len1=strlen(r);
			len2=strlen(l);
			for(int le=len2;le<len1;le++){
				l[le]='0';
			}
			for(int x=0;x<len1;x++){
				l2[x]=l[x];
				r2[x]=r[x];
			}
		}
		else{
			len1=strlen(l);
			for(int z=0;z<len1;z++){
				l2[z]=l[z];
				r2[z]=r[z];
			}
		}
		int ans[len1];
		for(int j=0;j<len1;j++){
			ans[j]=(int)l2[j]+(int)r2[j];
			ans[j]-=86;
			ans[j]%=10;
//			printf("%d",ans[j]);
		}
		printf("Case #%d: ",i);
		for(int k=len1-1;k>=0;k--){
			if(check==1 && ans[k]==len1-1){
				printf("%d",ans[k]);
			}
			else if(ans[k]!=0){
				printf("%d",ans[k]);
				check=1;
			}
			else if(ans[k]==0 && k==0){
				printf("0");
			}
		}
		printf("\n");
	}
 	return 0;
}
