#include <stdio.h>
#include <stdbool.h>

#define PLUS_NUM 1
#define MINUS_NUM 2
#define DIVIDE_NUM 3
#define MULTIPLE_NUM 4

int main(void) {
	long long int a,op,b;
	printf("Enter first number: ");
	scanf("%lld", &a);
	printf("Choose operation: \n\t[%d]: +"
			"\n\t[%d]: -\n\t[%d]: //\n\t[%d]: *\n",
			PLUS_NUM, MINUS_NUM, DIVIDE_NUM, MULTIPLE_NUM );
	scanf("%lld", &op);
	printf("Enter second number: ");
	scanf("%lld", &b);

	printf("Result: ");
	if (op == PLUS_NUM)
		printf("%lld\n", a+b);
	else if (op == MINUS_NUM)
		printf("%lld\n", a-b);
	else if (op == DIVIDE_NUM)
		printf("%lld\n", a/b);
	else if (op == MULTIPLE_NUM)
		printf("%lld\n", a*b);
	else
		printf("Undefined operation\n");

	return 0;
}
