#include <stdio.h>
#include <stdbool.h>

int main(void) {
	char op[2] = {' '};
	long double a,b;
	printf("Available operations: +,-,/,*,//,%%\n"
			"Enter first number then operation and then second number: ");
	scanf(" %Lf %s %Lf", &a, op, &b);

	printf("Result: ");
	if (op[0] == '+')
		printf("%Lf\n", a+b);
	else if (op[0] == '-')
		printf("%Lf\n", a-b);
	else if (op[0] == '*')
		printf("%Lf\n", a*b);
	else if (op[0] == '/' && op[1] == '/')
		printf("%lld\n", (long long int)a/(long long int)b);
	else if (op[0] == '/')
		printf("%Lf\n", a/b);
	else if (op[0] == '%')
		printf("%lld\n", (long long int)a%(long long int)b);
	else
		printf("Undefined operation\n");

	return 0;
}
