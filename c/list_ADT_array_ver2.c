#include<stdio.h>
#include<stdlib.h>
typedef struct Listnode
{
	int element;
	struct Listnode* next;
}ListNode;
ListNode* getnode()
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	return node;
}
ListNode* buildList(int n)
{
	ListNode* p = getnode();
	ListNode* L = p;
	p->element = 1;
	for (int i = 2; i <= n; i++)
	{
		p->next = getnode();
		p = p->next;
		p->element = i;
	}
	p->next = L;
	return L;
}
int runSimulation(ListNode* L, int n, int k)
{
	ListNode* p = L;
	while (p != p->next)
	{
		for (int i = 1; i < k; i++)
		{
			p = p->next;
		}
		ListNode* pnext = p->next;
		p->next = (p->next)->next;
		free(pnext);
		p = p->next;
	}
	return p->element;
}
int candle(int n, int k)
{
	ListNode* L = buildList(n);
	return runSimulation(L, n, k);
}
int main() {
	int n, k;
	printf("���� ���� ���ʸ� �ǳʶ�� ���� ������ �Է��Ͻÿ�:\n");
	scanf_s("%d%d", &n, &k);
	printf("�������� ���� �ʴ� %d�� ���Դϴ�.", candle(n, k));
}