#include <stdio.h>

float sum_elements(float a[], unsigned length) 
{
	int i;
	float result = 0;

	for (i = 0; (i <= length - 1) && (length > 0); i++) {		// To fix add in length > 0 condition
		result += a[i];
	}

	return result;
}

int main() 
{
	float array[] = { 3, 4, 7, 8, 10 };
	float ans;

	ans = sum_elements(array, 0);
	
	printf("%.1f\n", ans);



	return 0;
}