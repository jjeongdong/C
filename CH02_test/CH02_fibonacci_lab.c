#include <stdio.h>
#include <time.h>

int fib(int n);
int fib_iter(int n);
int fib_data[100];

int main(void)
{
	double result;
	clock_t start, end;
	double duration;

	start = clock();
	result = (double)fib_iter(40);
	end = clock();

	duration = (double)(end - start) / CLOCKS_PER_SEC;

	printf("> fib_iter(40) = %lf \n", result);
	printf("> fib_iter(40) 수행시간 = %lf sec\n", duration);

	start = clock();
	result = (double)fib(40);
	end = clock();

	duration = (double)(end - start) / CLOCKS_PER_SEC;
	printf("> fib(40) = %lf \n", result);
	printf("> fib(40) 수행시간 = %lf sec\n", duration);

	return 0;
}

int fib(int n)
{
	int tmp1;
	int tmp2;

	if (n == 0) return 0;
	if (n == 1) return 1;

	if (fib_data[n - 1] == 0) {	//아직 계산 된적이 없다
		tmp1 = fib(n - 1);
		fib_data[n - 1] = tmp1;
	}
	else {
		tmp1 = fib_data[n - 1];	//계산이 된 경우, 저장된 결과를 사용
	}

	if (fib_data[n - 2] == 0) {	//아직 계산 된적이 없다
		tmp2 = fib(n - 2);
		fib_data[n - 2] = tmp2;
	}
	else {
		tmp2 = fib_data[n - 2];	//계산이 된 경우, 저장된 결과를 사용
	}

	return(tmp1 + tmp2);
}

int fib_iter(int n)		//iterative fin 수열 계산
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	int pp = 0;
	int p = 1;
	int result = 0;

	for (int i = 2; i <= n; i++) {
		result = p + pp;
		pp = p;
		p = result;
	}
	return result;
}
