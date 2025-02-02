#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

#define MAX_VALUE_OF_CHARACTERS 256

int main(void) {
	char s[MAX_VALUE_OF_CHARACTERS] = {' '};
	char op[2] = {' '};
	char* ptr_s_subarr;
	long double a,b;

	printf("Available operations: +,-,/,*,//,%%\n"
			"Enter first number then operation and then second number: ");
	fgets(s, sizeof(s), stdin);

	a = strtol(s, &ptr_s_subarr, 0);
	parse_operator( &ptr_s_subarr, op, sizeof(op)/sizeof(op[0]) );
	b = strtol(ptr_s_subarr, NULL, 0);

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
	puts(	"[calculate]: Reached unreachable code."
			"Send angry email to the dev.");
	exit(EXIT_FAILURE);
}

void parse_operator(char** ps, char* op, int op_arr_len) {
	char* s = *ps;
	int op_len = 0;

	for (int i = 0; i < MAX_VALUE_OF_CHARACTERS; i++) {

		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\0') {
			if (op_len > op_arr_len) {
				puts("Your operator length is too big");
				exit(EXIT_FAILURE);
			}

			op[op_len] = s[i];
			op_len++;

		} else if (op_len != 0) {
			if (i + 1 != MAX_VALUE_OF_CHARACTERS)
				*ps = &s[i+1];
			else
				*ps = NULL;

			return;
		}

	}

	puts("There's no operator in the input");
	exit(EXIT_FAILURE);
}
