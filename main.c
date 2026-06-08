#include <stdio.h>

typedef struct {
	float data;
} Value;

int main(void)
{
	Value a;

	a.data = 2.0f;

	printf("a.data = %f\n", a.data);

	return 0;
}
