#include <stdio.h>
#include <stdbool.h>

#define PLUS_NUM 1
#define MINUS_NUM 2
#define DIVIDE_NUM 3
#define MULTIPLE_NUM 4
#define INT_DIVIDE_NUM 5
#define REMAINDER 6
int main(void) {
	long double a,op,b;
	printf("Available operations: [%d]: + [%d]: - [%d]: / [%d]: * [%d]: // [%d]: %%\n"
			"Enter first number then operation and then second number: ",
			PLUS_NUM, MINUS_NUM, DIVIDE_NUM, MULTIPLE_NUM, INT_DIVIDE_NUM, REMAINDER);
	scanf("%Lf%Lf%Lf", &a, &op, &b);

	printf("Result: ");
	if (op == PLUS_NUM)
		printf("%Lf\n", a+b);
	else if (op == MINUS_NUM)
		printf("%Lf\n", a-b);
	else if (op == DIVIDE_NUM)
		printf("%Lf\n", a/b);
	else if (op == MULTIPLE_NUM)
		printf("%Lf\n", a*b);
	else if (op == INT_DIVIDE_NUM)
		printf("%lld\n", (long long int)a/(long long int)b);
	else if (op == REMAINDER)
		printf("%lld\n", (long long int)a%(long long int)b);
	else
		printf("Undefined operation\n");

	return 0;
}
