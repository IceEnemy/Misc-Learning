#include <stdio.h>

int count;
char logo[105][105];

void bibi(char logo[][105], int index, int index2){
    if(logo[index][index2] == 'Q'){
        logo[index][index2] = '#';
        bibi(logo, index+1, index2);
        bibi(logo, index-1, index2);
        bibi(logo, index, index2+1);
        bibi(logo, index, index2-1);
    }
    else if(logo[index][index2] == '.'){
        count++;
        logo[index][index2] = '#';
        bibi(logo, index+1, index2);
        bibi(logo, index-1, index2);
        bibi(logo, index, index2+1);
        bibi(logo, index, index2-1);
    }
    else if(logo[index][index2] == '*'){
        count+=2;
        logo[index][index2] = '#';
        bibi(logo, index+1, index2);
        bibi(logo, index-1, index2);
        bibi(logo, index, index2+1);
        bibi(logo, index, index2-1);
    }
}

int main ()
{
    int row, column;
    int x,y;
    scanf("%d %d", &row, &column); getchar();
    
    for(int i = 0; i < row; i++){
        count = 0;
        for(int j = 0; j < column; j++){
            scanf("%c", &logo[i][j]);
            if(logo[i][j] == 'Q'){
                x = i;
                y = j;
            }
        } getchar();
    }
    bibi(logo, x, y);
    printf("%d\n", count);
    
    
    return 0;
}
