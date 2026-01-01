#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "parser.c"
#include "tokenizer.c"
#include "assembly.c"

int main(){

	char input[256];
	printf("Enter the arithmetic expression: ");
	fgets(input, sizeof(input), stdin);
	
	size_t len = strlen(input);
	if(len > 0 && input[len - 1] == '\n'){
		input[len - 1] = '\0';
	}

	Token *tokens = tokenize(input);
	int result;

	if (parse(tokens,&result)){
		printf("Parsed Result: %d\n", result);
		generate_assembly(tokens);
	}
	else{
		printf("Invalid Expression\n");
	}
	free(tokens);
	
	return 0;
}
