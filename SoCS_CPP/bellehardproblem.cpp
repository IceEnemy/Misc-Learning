#include <stdio.h>
int main(){
    int T;
    scanf("%d", &T);
    getchar();
    int questions;

    for(int i = 1; i <= T; i++)
    {
        scanf("%d", &questions);
        getchar();

        char answer[questions + 10];
        char answerkey[questions + 10];
        for(int x = 0; x < questions; x++)
        {
            scanf("%c", &answer[x]);
        }
	
        int counter = 0;
        for(int j = 0; j < questions; j++)
        {
            scanf("%c", &answerkey[j]);
            if(answer[j] == answerkey[j])
            {
                counter++;
            }
        }
        getchar();

//        int counter = 0;
//        for(int k = 0; k < questions; k++)
//        {
//            if(answer[k] == answerkey[k])
//            {
//                counter++;
//            }
//        }
        int score = (counter * 100) / questions;
        printf("Case #%d: %d\n", i, score);
    }
    return 0;
}

