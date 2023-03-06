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

		// 최소값 탐색
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

	// 난수 생성 및 출력
	for (i = 0; i < n; i++) {
		list[i] = rand();   // 난수 발생 범위 0~65000
	}

	printf("> 정렬 전:\n");
	for (i = 0; i < 100; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");

	start = clock(); // 호출한 시점의 시스템 clock값을 리턴
	selection_sort(list, n);		// 선택정렬 호출 
	end = clock();

	printf("\n> 정렬 후:\n");
	for (i = 0; i < 100; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");

	duration = (double)(end - start) / (double)CLOCKS_PER_SEC;
	printf("> 소요된 시간(초) = %lf sec.\n", duration);

	return 0;
}