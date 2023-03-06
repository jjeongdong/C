#include <stdio.h>
 
int main(void) {
	//자료구조.배열
	int data[11] = {1,2,3,4,5,6,7,8,9,10,11};
	//int max; // 최대값 저장.
	//int min; // 최솟값 저장.

	int total = 0;

	//min = data[0];

	for (int i = 0; i < sizeof(data)/sizeof(data[0]); i++) {
		total += data[i];
	}

	printf("> 배열 요소의 합 = %d\n", total);

	
	return 0;
}