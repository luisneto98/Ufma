#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int isdigit(char token);
int exp();
int term();
int factor();
void error();
void match(char expectedToken);


char token;

int main(){
	int result;
	token = getchar();

	result = exp();

	if(token=='\n')
		printf("Result = %d\n", result);
	else
		error();

	return 0;
}



int exp(){
	int temp = term();
	while(token == '+' || token == '-'){
		switch(token){
			case '+':
				match('+');
				temp += term();
				break;
			case '-':
				match('-');
				temp -= term();
				break;
		}
	}

	return temp;
}



int term(){
	int temp = factor();
	while(token == '*' || token == '/' || token == '%'){
        switch(token){
        case '*':
        	match('*');
			temp *= factor();
			break;
		case '/':
			match('/');
			temp /= factor();
			break;	
		case '%':
			match('%');
			temp %= factor();
			break;
        }
		
	}

	return temp;
}



int factor(){
	int temp;
	if(token == '('){
		match('(');
		temp = exp();
		match(')');
	} else if(isdigit(token)){
		ungetc(token, stdin);
		scanf("%d", &temp);
		token = getchar();
	} else {
		error();
	}

	return temp;
}



void error(){
	fprintf(stderr, "Error\n");
	exit(1);
}



void match(char expectedToken){
	if(token == expectedToken)
		token = getchar();
	else
		error();
}



int isdigit(char token){
	if(token >= '0' && token <= '9')
		return TRUE;
	return FALSE;
}
