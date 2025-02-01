#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "calculator.h"

int main(void) {
	char op[2] = {' '};
	long double a,b;
	printf("Available operations: +,-,/,*,//,%%\n"
			"Enter first number then operation and then second number: ");
	scanf(" %Lf %s %Lf", &a, op, &b);
	
	printf("Result: %Lf\n", calculate(a, op, b));
	return EXIT_SUCCESS;
}

long double calculate(long double a, char* op, long double b) {
	if (op[0] == '+')
		return a + b;
	else if (op[0] == '-')
		return a - b;
	else if (op[0] == '*')
		return a * b;
	else if (op[0] == '/' && op[1] == '/')
		return (long double)( (long long int)a / (long long int)b );
	else if (op[0] == '/')
		return a / b;
	else if (op[0] == '%')
		return (long double)( (long long int)a % (long long int)b );
	else {
		printf("Operation: \"%s\" is not defined\n", op);
		exit(EXIT_FAILURE);
	}
	puts("[calculate]: Reached unreachable code. Send angry email to developer");
	exit(EXIT_FAILURE);
}
