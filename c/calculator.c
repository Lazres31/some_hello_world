#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculator.h"

#define MAX_VALUE_OF_CHARACTERS 2048
#define ACCEPTABLE_OPERATORS {'+','-','*','/','%'}

int main(int argc, char** argv) {
	char s[MAX_VALUE_OF_CHARACTERS] = {' '};
	char op[2] = {' '};
	char* ptr_s_subarr = s;
	long double a,b;
	
	if (argc <= 1) {
		printf("Available operations: +,-,/,*,//,%%\n"
			"Enter first number, then operation"
			"and then second number: ");
		char* fgets_status = NULL;
		fgets_status = fgets(s, sizeof(s)/sizeof(s[0]), stdin);
		if (fgets_status == NULL) {
			puts("There's no meaningfull symbols in the string");
			exit(EXIT_FAILURE);
		}
	}
	else {
		//Parse characters from 2 dimensional argv array to
		//one dimensional s array
		int iterations_sum = 0;
		for (int i = 1; i < argc; i++) {
			for (int j = 0; argv[i][j] != '\0'; j++) {
				s[iterations_sum] = argv[i][j];
				iterations_sum++;
			}
		}
	}

	a = strtol(ptr_s_subarr, &ptr_s_subarr, 0);
	while (ptr_s_subarr[0] != '\0') {
		int parse_status = parse_operator( &ptr_s_subarr, op,
									sizeof(op)/sizeof(op[0]) );
		if (parse_status == 1)
			break;

		b = strtol(ptr_s_subarr, &ptr_s_subarr, 0);
		a = calculate(a, op, b);
	}

	if (argc <= 1)
		printf("Result: ");
	printf("%Lf\n", a);

	return EXIT_SUCCESS;
}

int parse_operator(char** ps, char* op, int op_arr_len) {
	char op_symbols[] = ACCEPTABLE_OPERATORS;
	char* s = *ps;
	int op_len = 0;

	for (int i = 0; i <= op_arr_len && s[i] != '\0'; i++) {

		if (strchr( op_symbols, s[i] ) != NULL) {
			op[op_len] = s[i];
			op_len++;

		} else if (op_len != 0) {
			*ps = &s[i];
			return 0;
		}

	}
	return 1;
}

long double calculate(long double a, char* op, long double b) {
	if (a == 0) puts("WARNING: a = 0");
	if (b == 0) puts("WARNING: b = 0");
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
}
