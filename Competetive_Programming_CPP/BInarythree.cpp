#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int size;
		scanf("%d",&size);
		int num[size];
		for(int j=0;j<size;j++){
			scanf("%d",&num[j]);
		}
		int ttl=0; //total yang valid
		int ans=0; //berapa yang XORnya lebih dari or sama dengan 3
		int XOR; //int untuk dpt XORnya
		for(int j=0;j<size;j++){
			for(int k=0;k<size;k++){
				int sum=0;
				if(j>k){ //ini biar gak ada repeat scan
					ttl++;
					XOR=num[k]^num[j]; //^ itu untuk dpt XOR
					while (XOR>0){
						sum+=XOR&1; //>>= untuk geser ke kanan 1 kali while XOR&1 itu untuk ambil nomor terakhir(paling kanan) di binarynya (bit)
						XOR>>=1;
					}
					if(sum >=3){
						ans++;
					}	
				}
			}
		}
		printf("Case #%d: %d %d\n",i,ans,ttl-ans);
	}
 	return 0;
}

