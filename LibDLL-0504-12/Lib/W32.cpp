#include"stdafx.h"
#include"W32.h"

#define error -1
#define PI 3.1415926


int factorial(int n) {
	int sum=1;
	if (n > 13)  return error;
	for (int i = 1; i <= n; i++) {
		sum *= i;
	}
	return sum;
}


