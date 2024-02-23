#include <stdio.h>

void swap (long long int *a, long long int *b){
    int temp = *a;
    *a = *b;
    *b = temp; 
}

void bubbleSort(long long  int hit[], long long int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(hit[j] > hit[j+1]){
                swap(&hit[j], &hit[j+1]);
            }
        }
    }
}

int main(){
    
    long long int tc;
    scanf("%lld", &tc); 
    
    long long int hit[tc+5]; 
    for(int i = 0; i < tc; i++){
        scanf("%lld", &hit[i]); 
    }
    
    bubbleSort(hit, tc);
    
    long long int strength; 
    scanf("%lld", &strength); 
    
    long long  int result = 0;
    long long  int level;
    for(int i = 0; i < tc; i++){
        result += hit[i];
        if(result <= strength){
            level = i; 
        }
        else break;  

//        strength -= hit[i]; 
//        if(strength < 0) break;
//        level++; 
    }
    printf("%lld\n", level+1);
    
    
    return 0; 
}

