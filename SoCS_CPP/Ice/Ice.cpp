#include <stdio.h>

int main()
{
	FILE *fp = fopen("testdata.in","r");
	int test;
	fscanf(fp,"%d",&test);
	for(int i=1;i<=test;i++){
		int n;
		fscanf(fp,"%d",&n);
		int num[n];
		int total=0;
		int perimeter=0;
		for(int j=0;j<n;j++){
			fscanf(fp,"%d",&num[j]);
			total+=num[j];
			perimeter+=2*(2+num[j]*2);
		}
		int area=total*4;
		
		for(int j=0;j<n-1;j++){
			int min;
			if(num[j]>num[j+1]){
				min=num[j+1]*4;
			}
			else{
				min=num[j]*4;
			}
			perimeter-=min;
		}
		
		printf("Case #%d: %d %d\n",i,perimeter,area);
	}
	fclose(fp);
 	return 0;
}

