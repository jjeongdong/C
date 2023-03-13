#include <stdio.h>
#include <time.h>
double slow_power(double x, int n);
double power(double x, int n);

int main(void)
{
	double result;
	clock_t start, end;
	double duration;

	start = clock();
	for (int i = 0; i < 1000000; i++) {	//�ӵ� ������ ���� �ݺ���
		result = slow_power(2.0, 1000);	//�ݺ����, iterative
	}
	end = clock();
	duration = (double)(end - start) / (double)CLOCKS_PER_SEC;

	printf("> slow power result = %lf\n", result);
	printf("> slow power ���� �ð�= %lf sec\n", duration);


	start = clock();
	for (int i = 0; i < 1000000; i++) {	//�ӵ� ������ ���� �ݺ���
		result = power(2.0, 1000);
	}

	end = clock();
	duration = (double)(end - start) / (double)CLOCKS_PER_SEC;
	
	printf("> power result = %lf\n", result);
	printf("> power ���� �ð�= %lf sec\n", duration);
	return 0;
}

double slow_power(double x, int n)
{
	int i;
	double result = 1.0;

	for (i = 0; i < n; i++) {	//O(n)
		result = result * x;
	}

	return(result);
}

double power(double x, int n)	//O(log n)
{
	if (n == 0) {
		return 1;
	} else if ((n % 2) == 0) {
		return power(x * x, n / 2);		//n�� ¦��
	} else {
		return x * power(x * x, (n - 1) / 2);	//n�� Ȧ��
	}
}
