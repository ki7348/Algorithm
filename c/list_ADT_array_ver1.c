#include<stdio.h>
#include<stdlib.h>
int* arrayver2;
int candle(int n, int k);
void buildList(int A[], int n);
int runSimulation(int A[], int n, int k);
int candle(int n, int k)
{
	arrayver2 = (int*)malloc(sizeof(int) * n);
	buildList(arrayver2, n);
	return runSimulation(arrayver2, n, k);
}
void buildList(int A[], int n)
{
	for (int r = 0; r < n - 1; r++)
		A[r] = r + 1;
}
void erase(int r)
{
	int i, n;
	n = sizeof(arrayver2); for (i = r + 1; i <= n; i++)
	{
		arrayver2[i - 1] = arrayver2[i];
	}
}
int runSimulation(int A[], int n, int k)
{
	int r = 0;
	while (n > 1)
	{
		r = (r + k) % n;
		erase(r);
		n -= 1;
	}
	return A[0];
}
int main()
{
	int n, k;
	printf("초의 수와 양초를 건너띄울 초의 개수를 입력하시오:\n");
	scanf_s("%d%d", &n, &k);
	printf("마지막에 남는 초는 %d번 초입니다.", candle(n, k));
}