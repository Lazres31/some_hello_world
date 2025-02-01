#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

#define MAX_VALUE_OF_CHARACTERS 256

int main(void) {
	char s[MAX_VALUE_OF_CHARACTERS] = {' '};
	char op[2] = {' '};
	char* tmp;
	long double a,b;

	printf("Available operations: +,-,/,*,//,%%\n"
			"Enter first number then operation and then second number: ");
	fgets(s, sizeof(s), stdin);

	a = strtol(s, &tmp, 0);
	parse_operator( &tmp, op, sizeof(op)/sizeof(op[0]) );
	b = strtol(tmp, NULL, 0);

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

void parse_operator(char** ps, char* res, int res_len) {
	char* s = *ps;
	int res_cur_len = 0;
	for (int i = 0; i < MAX_VALUE_OF_CHARACTERS; i++) {
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\0') {
			if (res_cur_len > res_len) {
				puts("[parse_operator]: result array is too small");
				exit(EXIT_FAILURE);
			}
			res[res_cur_len] = s[i];
			res_cur_len++;
		} else if (res_cur_len != 0) {
			if (i + 1 != MAX_VALUE_OF_CHARACTERS) 
				*ps = &s[i+1];
			else *ps = NULL;
			return;
		}
	}
	puts("There's no operator in the string");
	exit(EXIT_FAILURE);
}
