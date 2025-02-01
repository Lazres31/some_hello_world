#ifndef CALCULATOR
#define CALCULATOR

long double calculate(long double a, char* op, long double b);

void parse_operator(char** s, char* res, int res_len);

#endif
