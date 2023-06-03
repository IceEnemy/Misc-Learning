#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_ELEMENT = 1000;

// simulate a tree using an array
int heap[MAX_ELEMENT];
int heap_size = 0;

int parent(int idx){
	return (idx-1)/2;
}

int leftChild(int idx){
	return idx*2+1;//parent of the index
}

int rightChild(int idx){
	return idx*2+2;//parent of the index
}



// index of the child
int assert(int parentIdx, int childIdx){
	return heap[parentIdx] < heap[childIdx]; //minheap
//	return heap[parentIdx] > heap[childIdx]; //maxheap
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void upheap(int idx){
	if(idx <= 0) return;
	int parentIdx = parent(idx);
	if(!assert(parentIdx,idx)){
		swap(&heap[idx],&heap[parentIdx]);
		upheap(parentIdx);
	}
}

void insert(int val){
	heap[heap_size] = val;
	upheap(heap_size);
	heap_size++;
}


// pops the topmost element (root)
//which is also the smallest or largest value depending on the heap type

void downheap(int idx){
	if(idx >= heap_size) return;
	
	int repIdx = idx;
	int leftIdx = leftChild(idx);
	int rightIdx = rightChild(idx);
	
	if(leftIdx < heap_size && !assert(repIdx,leftIdx)) repIdx = leftIdx;
	
	if(rightIdx < heap_size && !assert(repIdx,rightIdx)) repIdx = rightIdx;
	
	if(repIdx != idx){
		swap(&heap[repIdx],&heap[idx]);
		downheap(repIdx);
	}
}

int del(){
	int temp = heap[0];
	
	heap[0] = heap[--heap_size];
	downheap(0);
	
	return temp;		
}



void inOrder(int idx,int tabs){
	if(idx >= heap_size) return;
	inOrder(rightChild(idx),tabs+1);
	for(int i = 0; i<tabs; i++){
		printf("\t");
	}
	printf("%d\n",heap[idx]);
	inOrder(leftChild(idx),tabs+1);
}

void print(){
	printf("=================================\n");
	inOrder(0,0);
	printf("=================================\n");
}

int main()
{
	insert(20);
	insert(10);
	insert(5);
	print();
	insert(1);
	print();
	
	while(heap_size > 0){
		printf("Popped: %d\n",del());
//		print();
	}
 	return 0;
}

