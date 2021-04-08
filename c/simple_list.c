#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode
{
	int data;
	struct ListNode* link;
}ListNode;
typedef struct
{
	ListNode* head;
}LinkedListType;
void init(LinkedListType* L)
{
	L->head = NULL;
}
void addFirst(LinkedListType* L, int item)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = item;
	node->link = L->head;
	L->head = node;
}
void add(LinkedListType* L, int pos, int item)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* before = L->head;
	for (int i = 0; i < pos - 1; i++)
		before = before->link;
	node->data = item;
	node->link = before->link;
	before->link = node;
}
void addLast(LinkedListType* L, int item)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* before = L->head;
	node->data = item;
	while (before->link != NULL)
		before = before->link;
	node->link = before->link;
	before->link = node;
}void deleteFirst(LinkedListType* L)
{
	ListNode* remove = L->head;
	L->head = remove->link;
	free(remove);
}
void delete(LinkedListType* L, int pos)
{
	ListNode* p = L->head;
	for (int i = 0; i < pos - 2; i++)
		p = p->link;
	ListNode* delete = p->link;
	p->link = delete->link;
	free(delete);
}
void deleteLast(LinkedListType* L)
{
	ListNode* prev = L->head;
	ListNode* delete = L->head->link;
	while (delete->link != NULL)
	{
		prev = delete;
		delete = delete->link;
	}
	free(delete);
	prev->link = NULL;
}
void set(LinkedListType* L, int pos, int item)
{
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;
	p->data = item;
}
int get(LinkedListType* L, int pos)
{
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;
	return p->data;
}
void printlist(LinkedListType* L)
{
	for (ListNode* p = L->head; p != NULL; p = p->link)
		printf("[%d]->", p->data);
	printf("NULL\n");
}
void main() {
	LinkedListType list;
	init(&list);
	addFirst(&list, 10);
	addFirst(&list, 20);
	addFirst(&list, 30);
	addFirst(&list, 40);
	addFirst(&list, 50);
	addFirst(&list, 60);
	addLast(&list, 70);
	printf("�ʱ���� ���\n");
	printlist(&list);
	getchar();
	deleteFirst(&list);
	deleteLast(&list);
	printf("�� �� �� �� ������ �����ϰڽ��ϴ�.\n");
	printlist(&list);
	getchar();
	printf("2�� ���ڿ� ���� 100�� �����ϰڽ��ϴ�.\n");
	add(&list, 2, 100);
	printlist(&list);
	printf("\n");
	printf("4�� ��� �����͸� �����ϰڽ��ϴ�.\n");
	delete(&list, 4);
	printlist(&list);
	getchar();
	int pos;
	printf("�� �� ����� ���� ��ȯ�ұ��?");
	scanf_s("%d", &pos);
	printf("%d�� ����� ���� %d\n", pos, get(&list, pos));
}