#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    char val;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node *addNode(char value) {
    struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
    curr->val = value;
    curr->next = curr->prev = NULL;
    return curr;
}

void firstData(char value) {
    struct Node *curr = addNode(value);
    head = tail = curr;
}

void pushHead(char value) {
    struct Node *curr = addNode(value);
    head->prev = curr;
    curr->next = head;
    head = curr;
}

void pushTail(char value) {
    struct Node *curr = addNode(value);
    tail->next = curr;
    curr->prev = tail;
    tail = curr;
}

void pushMid(char value) {
    struct Node *curr = addNode(value);
    if (!head) {
        firstData(value);
    } else if (value <= head->val) {
        pushHead(value);
    } else if (value >= tail->val) {
        pushTail(value);
    } else {
        struct Node *temp = head;
        while (temp->next != NULL && temp->next->val < value) {
            temp = temp->next;
        }
        curr->next = temp->next;
        temp->next->prev = curr;
        curr->prev = temp;
        temp->next = curr;
    }
}

void printList() {
    struct Node *temp = head;
    printf("NULL");
    while (temp != NULL) {
        printf("<-%c->", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    pushMid('1');
    pushMid('6');
    pushMid('4');
    pushMid('3');
    printList();
    return 0;
}

