#include <stdio.h>
 
int main(void) {
	//�ڷᱸ��.�迭
	int data[11] = {1,2,3,4,5,6,7,8,9,10,11};
	//int max; // �ִ밪 ����.
	//int min; // �ּڰ� ����.

	int total = 0;

	//min = data[0];

	for (int i = 0; i < sizeof(data)/sizeof(data[0]); i++) {
		total += data[i];
	}

	printf("> �迭 ����� �� = %d\n", total);

	
	return 0;
}