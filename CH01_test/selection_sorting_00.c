#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n)
{
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;

		// �ּҰ� Ž��
		for (j = i + 1; j < n; j++) {
			if (list[j] < list[least]) {
				least = j;
			}
		}
		// 
		SWAP(list[i], list[least], temp);
	}
}

int main(void)
{
	int i;
	clock_t start, end;
	double duration;


	n = MAX_SIZE;	
	srand(1);   //srand(time(NULL));

	// ���� ���� �� ���
	for (i = 0; i < n; i++) {
		list[i] = rand();   // ���� �߻� ���� 0~65000
	}

	printf("> ���� ��:\n");
	for (i = 0; i < 100; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");

	start = clock(); // ȣ���� ������ �ý��� clock���� ����
	selection_sort(list, n);		// �������� ȣ�� 
	end = clock();

	printf("\n> ���� ��:\n");
	for (i = 0; i < 100; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");

	duration = (double)(end - start) / (double)CLOCKS_PER_SEC;
	printf("> �ҿ�� �ð�(��) = %lf sec.\n", duration);

	return 0;
}