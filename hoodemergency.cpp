#include <stdio.h>

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        int N;
        int K;
        char A[10000];
        int stair = 0;
        int left = 0;
        int right = 0;
        scanf("%d %d", &N, &K); getchar();
        scanf("%s", &A); getchar();
        for(int h = 0; h < N; h++){
            if(A[h] == '1'){
                stair++;
            }
        }
        for(int l = 0; l < N; l++){
            if(A[l] == '0'){
                left++;
            }else{
                break;
            }
        }
        for(int m = N-1; m >= 0; m--){
            if(A[m] == '0'){
                right++;
            }else{
                break;
            }
        }
        if(K > N){
            printf("Case #%d: Alive\n", i);
        }else{
            if(stair < 2){
                printf("Case #%d: Dead\n", i);
            }else{
                if(left < K && right < K){
                    printf("Case #%d: Alive\n", i);
                }else if(left >= K || right >= K){
                    printf("Case #%d: Dead\n", i);
                }
            }
        }

    }
    return 0;
}

