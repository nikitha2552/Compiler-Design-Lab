#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SUCCESS 1

int E(), Edash(), T(), Tdash(), F();

void error(){
	puts("--------------------------------");
	puts("Error in parsing String");
	exit(1);
}

const char *cursor;
char string[64];

int main() {
	puts("Enter the string");
	scanf("%s", string); 
	cursor = string;
	puts("\n--NOTE : $ represents epsilon--\n");
	puts("Input		 Action");
	puts("--------------------------------");

	if (E() && *cursor == '\0') {
		puts("--------------------------------");
		puts("String is successfully parsed");
		puts("It is a valid statement");
		return 0;
	} 
	else {
		error();
		return 1;
	}
}

 
// Grammar rule: E -> T E'
int E() {
	printf("%-16s E -> T E'\n", cursor);
	if (T()) { // Call non-terminal T
		if (Edash()) // Call non-terminal E'
			return SUCCESS;
		else
			error();
	} 
	else
		error();
}

// Grammar rule: E' -> + T E' | $
int Edash() {
	if (*cursor == '+') {
		printf("%-16s E' -> + T E'\n", cursor);
		cursor++;
		if (T()) { // Call non-terminal T
			if (Edash()) // Call non-terminal E'
				return SUCCESS;
			else
				error();
		} 
		else
			error();
	}
	else {
		printf("%-16s E' -> $\n", cursor);
		return SUCCESS;
	}
}

// Grammar rule: T -> F T'
int T() {
	printf("%-16s T -> F T'\n", cursor);
	if (F()) { // Call non-terminal F
		if (Tdash()) // Call non-terminal T'
			return SUCCESS;
		else
			error();
	} 
	else
		error();
}

 
// Grammar rule: T' -> * F T' | $
int Tdash() {
	if (*cursor == '*') {
		printf("%-16s T' -> * F T'\n", cursor);
		cursor++;
		if (F()) { // Call non-terminal F
			if (Tdash()) // Call non-terminal T'
				return SUCCESS;
			else
				error();
		} 
		else
			error();
	} 
	else {
		printf("%-16s T' -> $\n", cursor);
		return SUCCESS;
	}
}

// Grammar rule: F -> ( E ) | id
int F() {
	if (*cursor == '(') {
		printf("%-16s F -> ( E )\n", cursor);
		cursor++;
		if (E()) { // Call non-terminal E
			if (*cursor == ')') {
				cursor++;
				return SUCCESS;
			} 
			else
				error();
		} 
		else
			error();
	} 
	else if (isalpha(*cursor)) {
		printf("%-16s F -> id\n", cursor);
		cursor++;
		return SUCCESS;
	} 
	else
		error();
}
 
