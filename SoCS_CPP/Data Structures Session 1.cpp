#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
========================
Pointer and Array Review
========================

pointers refers to another value (the address of data)
& means address
* means content of

arrays are a type of pointer

printf("%d", *people) --> people[0]
*(people+1) --> people[1]
*(people+10) --> people[10]

for strings, we need size+1 for the array size because we need null for the last index

sizes
char - 1
float - 3
int - 4

addresses may be random everytime we compile

pointer to point another pointer --> **ppx(double pointers) = &px (single pointer)
look for (how to do swap without temporary)


Arrays are a collection of the same datatypes, index from 0 to n-1

Operations in Array

Traversal -> go through all the data
Insertion -> put data
Searching -> search data
Deletion -> erase data (change the data or skip the data)
Merging -> combine arrays
Sorting -> sort arrays



===============
Data Structures
===============

We will probably get data with different data types like
NIM  |  Name  |  Time of Attendance
for these, we need structs
(abstract data types, heterogen datatypes become one single datatype)

the name for structs or classes use uppercase <-- ?

struct data{
	char NIM[11]
	char name[110]
	int time
};

data x --> a variable of data
data arr[100] --> an array of data
how to call:
arr[i].NIM
arr[i].name
arr[i].time

you can declare struct variables like this (global variable)

struct data{
	char NIM[11]
	char name[110]
	int time
}a,b;

Data Structure --> an arrangement of data
Arr (above)

Linked Lists
a dynamic data structure (we dont have to declare how much data in the first place)
the bad side --> there might not be enough memory to use

Queue
The element that was first inserted will be out first (pretty much a queue)

Stacks
has a TOP variable
it's like the reverse of a queue
last one in is the first one out

Binary Trees
used for sorting, encryption, MLM????
a collection of nodes, each node has a left and right pointer


============
Linked Lists
============

linked lists doesn't exist at the start

we have 3 parameters
*head,*curr(current),*tail
if these == null, there is no data

how t ocheck if its the first data
if(head==NULL) --> first data

push, pop, print
push = operation to add new data
pop = operation to delete data
print = operation to print data

basic code:
struct Tnode{
	int value;
	struct tnode *next;
};
struct Tnode *head = 0;

struct Tnode *curr = (struct Tnode*)malloc(sizeof(struct Tnode));
curr ->

push: front push, back push, middle push
*head --> paling depan
*tail --> paling belakang

if(head == null)
{
head = tail
tail = curr
tail->next=null
}
else{
tail->next = curr
tail = curr
tail->next = null
}

push front
{
curr->next = head
head = curr
}

push mid (data more than 1)

2 ways
make it index
check if index >= 1 or amount >= 2, then we know there are more than 2 datas

h  t
5->10
 c
 7
{
curr->next = tail
head->next = curr
}
only if we have 2 data (we know where to put it)

h			t	
1->3->4->7->10
		c
		6

temp = head;
while(temp->next != null && );
if(temp->next < curr)
temp=temp->next;

curr->next = temp->next
temp->next = curr

sigle link list only has one pointer
*down/*next/*prev/*up
usually next
double has two, multiple has more than two



*/


/*
1. what is the difference and similiarities between arrays and pointers? give example

Difference:
pointers point to a certain value and provide the address while arrays store certain values of the same datatype.
Similiarities:
Arrays are a type of pointers, they  

2. if there is number
1, 5, 6, 7, 9, 12
push front,single pointer.
make the code. what is the output of the code?

3. Make a code that can do sort number while push
 if(lesser) push depan
 	if mid push tengtah
 		if bigger push tail

*/

struct Node{
	int value;
	struct Node *next;
};

int main()
{
	
 	return 0;
}

