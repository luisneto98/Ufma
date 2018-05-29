#include <stdio.h>
#include <stdlib.h>
#include "syntaxTree.h"

#define TRUE 1
#define FALSE 0

int isdigit(char token);
void error();
void match(char expectedToken);
syntaxTree *expTree();
syntaxTree *termTree();
syntaxTree *factorTree();

char token;

int main(){
  syntaxTree *result;
  token = getchar();

  result = expTree();

  if(token=='\n')
	printf("Result = %d\n", calcSyntaxTree(result));
  else
	error();

  return 0;
}



syntaxTree *expTree(){
  syntaxTree *temp = termTree();
  syntaxTree *newTemp;	

  while(token == '+' || token == '-'){
	newTemp = createSyntaxNode((int) token, OPERATOR);
	match(token);
	lChild(newTemp, temp);
	rChild(newTemp, termTree());
	temp = newTemp;
  }
	
  return temp;
}



syntaxTree *termTree(){
  syntaxTree *temp = factorTree();
  syntaxTree *newTemp;

  while(token == '*' || token == '/' || token == '%'){
	newTemp = createSyntaxNode((int) token, OPERATOR);
	match(token);
	lChild(newTemp, temp);
	rChild(newTemp, factorTree());
	temp = newTemp;
  }

  return temp;
}



syntaxTree *factorTree(){
  syntaxTree *temp = NULL;
  int auxTemp;

  if(token == '('){
	match('(');
	temp = expTree();
	match(')');
  } else if(isdigit(token)){
	ungetc(token, stdin);
	scanf("%d", &auxTemp);
	temp = createSyntaxNode(auxTemp, NUMBER);
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


