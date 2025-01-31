#include <stdio.h>
#include <stdbool.h>

int main(void) {
	char op;
	long double a,b;
	printf("Available operations: +,-,/,*,//,%%\n"
			"Enter first number then operation and then second number: ");
	scanf(" %Lf %c %Lf", &a, &op, &b);

	printf("Result: ");
	if (op == '+')
		printf("%Lf\n", a+b);
	else if (op == '-')
		printf("%Lf\n", a-b);
	else if (op == '/')
		printf("%Lf\n", a/b);
	else if (op == '*')
		printf("%Lf\n", a*b);
	else if (op == '/') //fixme
		printf("%lld\n", (long long int)a/(long long int)b);
	else if (op == '%')
		printf("%lld\n", (long long int)a%(long long int)b);
	else
		printf("Undefined operation\n");

	return 0;
}
