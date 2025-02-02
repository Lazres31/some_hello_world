#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculator.h"

#define MAX_VALUE_OF_CHARACTERS 256
#define ACCEPTABLE_OPERATORS {'+','-','*','/','%'}

int main(int argc, char** argv) {
	char s[MAX_VALUE_OF_CHARACTERS] = {' '};
	char op[2] = {' '};
	char* ptr_s_subarr;
	long double a,b;
	
	if (argc <= 1) {
		printf("Available operations: +,-,/,*,//,%%\n"
			"Enter first number then operation and then second number: ");
		fgets(s, sizeof(s), stdin);
	}
	else {
		//Parse characters from 2 dimension argv array to
		//one dimension s array
		int iterations_sum = 0;
		for (int i = 1; i < argc; i++) {
			for (int j = 0; argv[i][j] != '\0'; j++) {
				s[iterations_sum] = argv[i][j];
				iterations_sum++;
			}
		}
	}

	a = strtol(s, &ptr_s_subarr, 0);
	parse_operator( &ptr_s_subarr, op, sizeof(op)/sizeof(op[0]) );
	b = strtol(ptr_s_subarr, NULL, 0);

	if (argc <= 1)
		printf("Result: ");
	printf("%Lf\n", calculate(a, op, b));

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
	char op_symbols[] = ACCEPTABLE_OPERATORS;
	char* s = *ps;
	int op_len = 0;

	for (int i = 0; i < MAX_VALUE_OF_CHARACTERS; i++) {

		if (strchr( op_symbols, s[i] ) != NULL) {
			if (op_len > op_arr_len) {
				puts("Your operator length is too big");
				exit(EXIT_FAILURE);
			}

			op[op_len] = s[i];
			op_len++;

		} else if (op_len != 0) {
			if (i != MAX_VALUE_OF_CHARACTERS)
				*ps = &s[i];
			else
				*ps = NULL;
			return;
		}

	}

	puts("There's no operator in the input");
	exit(EXIT_FAILURE);
}
