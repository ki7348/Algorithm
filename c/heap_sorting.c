#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#define MAX_ELEMENT 999
#define MAX_STACK_SIZE 999



typedef struct {
	int heap[MAX_ELEMENT];
	int heap_size;
}HeapType;


typedef struct {
	int data[MAX_STACK_SIZE];
	int top;
}StackType;

//스택 함수
void init_stack(StackType* s)
{
	s->top = -1;
}
int is_empty(StackType* s)
{
	return (s->top == -1);
}
void push(StackType* s, int item)
{
	s->data[++(s->top)] = item;
}
int pop(StackType* s)
{
	if (is_empty(s))
	{
		printf("Stack overflow\n");
		exit(1);
	}
	return s->data[(s->top)--];
}
//히프 함수
void init_heap(HeapType* h)
{
	h->heap_size = 0;
}
void upHeap(HeapType* h)
{
	int i = h->heap_size;
	int key = h->heap[i];
	while ((i != 1) && (key < h->heap[i / 2]))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = key;
	
}
void insertItem(HeapType* h, int key)
{
	h->heap_size += 1;
	h->heap[h->heap_size] = key;
	upHeap(h);
}
void printHeap(HeapType*h) {
	for (int i = 1; i <= h->heap_size; i++)
	{
		printf("[%d] ", h->heap[i]);
		Sleep(500);
	}
	printf("\n");
}


//마지막 노드 함수
void binaryExpansion(int i, StackType* s) {
	while (i >= 2)
	{
		push(s, (i % 2));
		i /= 2;
	}
	push(s, i);
	return;

}

int findLastNode(int h, int n) {
	StackType s;
	init_stack(&s);
	binaryExpansion(n, &s);
	pop(&s);



	while (!is_empty(&s)) {
		int bit = pop(&s);
		if (bit == 0)
		{
			h = h * 2;
		}
		else
			h = h * 2 + 1;
	}

	return h;

}






int main() {
	HeapType heap;
	init_heap(&heap);
	srand(time(NULL));
	int heap_size;
	printf("입력할 원소의 개수:");
	scanf_s("%d", &heap_size);
	for (int i = 1; i <= heap_size; i++)
		insertItem(&heap,rand() % 100);
	
	
	printHeap(&heap);

	getchar();
	
	printf("마지막 노드의 값은 [%d]입니다.", heap.heap[findLastNode(1, heap.heap_size)]);
}