#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


struct Node
{
   char word;
   Node *next;
   Node *prev;
} *head = NULL, *tail = NULL, *head2 = NULL, *tail2 = NULL;


Node *makeNode(char word)
{
   Node *newNode = (Node *)malloc(sizeof(Node));
   newNode->word = word;
   newNode->next = newNode->prev = NULL;
   return newNode;
}


void pushFirstLL(char word) // this is basically pushMid but simplified hehe
{
   Node *newNode = makeNode(word);
   if (head == NULL) // this works for both pushHead and pushTail
   {
       head = tail = newNode;
   }
   else if (word < head->word) // this is pushHead
   {
       newNode->next = head;
       head->prev = newNode;
       head = newNode;
   }
   else if (word > tail->word || word == ' ') // this is pushTail
   {
       tail->next = newNode;
       newNode->prev = tail;
       tail = newNode;
   }
   else
   {
       Node *curr = head;
       while (curr->next->word < word && curr->next != NULL)
       {
           curr = curr->next; // this is for the looping process.
       }
       curr->next->prev = newNode;
       newNode->prev = curr;
       newNode->next = curr->next;
       curr->next = newNode;
   } // the inserted letter will already be sorted this way.
}


void pushSecondLL(char word)
// PushTail and we scan from behind.
{
   Node *newNode = makeNode(word);
   if (head2 == NULL)
   {
       head2 = tail2 = newNode;
   }
   else
   {
       tail2->next = newNode;
       newNode->prev = tail2;
       tail2 = newNode;
   }
}


void switchLL()
{
   Node *temp = tail; // it knows that it will access the first LL since its tail not tail2.
   while (temp != head)
   {
       pushSecondLL(temp->word);
       temp = tail->prev;
       temp->next = tail->prev = NULL;
       free(tail);
       tail = temp;
   }
   // this is a condition we use when our remaining node is our head.
   pushSecondLL(temp->word);
   head = tail = NULL;
   free(head);
}


void print2()
{
   Node *temp = head2;
   while (temp != NULL)
   {
       printf("%c", temp->word); // we want to print the temp's word.
       temp = temp->next;
   }
   printf("\n");
}


int main()
{
   char string[1010];
   scanf("%[^\n]", string);
   getchar();


   int start = 0;


   for (int i = 0; i < strlen(string); i++)
   {
       if (string[i] == ' ' || i == strlen(string) - 1)
       {
           for (int j = start; j <= i; j++) // no need i - 1 so we can also send the space.
           {
               pushFirstLL(tolower(string[j]));
           }
           switchLL();
           start = i + 1;
       }
   }
   print2();
   return 0;
}


