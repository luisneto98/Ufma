#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define ERROR -999


typedef enum { NUMBER, OPERATOR } typeNode;	

typedef struct _syntaxtree_{
  int data;
  typeNode type;
  struct _syntaxtree_ *lchild, *rchild;
} syntaxTree;



syntaxTree *createSyntaxNode(int data, typeNode type){
  syntaxTree *newNode = (syntaxTree *) malloc(sizeof(syntaxTree));

  if( newNode != NULL ){
	newNode->data = data;
	newNode->type = type;
	newNode->lchild = NULL;
	newNode->rchild = NULL;

	return newNode;
  } 

  return NULL;
}



void lChild(syntaxTree *node, syntaxTree *child){
  if( node != NULL )
	if( child != NULL )
	  node->lchild = child;
	
}



void rChild(syntaxTree *node, syntaxTree *child){
  if( node != NULL )
	if( child != NULL )
	  node->rchild = child;
	
}



int calcSyntaxTree(syntaxTree *node){
  if( node != NULL ){
	if( node->type == NUMBER ) return node->data;
	
	switch((char) node->data){
	case '+':
	  return calcSyntaxTree(node->lchild) + calcSyntaxTree(node->rchild);
	case '-':
	  return calcSyntaxTree(node->lchild) - calcSyntaxTree(node->rchild);
	case '*':
	  return calcSyntaxTree(node->lchild) * calcSyntaxTree(node->rchild);
	case '/':
	  return calcSyntaxTree(node->lchild) / calcSyntaxTree(node->rchild);
	case '%':
	  return calcSyntaxTree(node->lchild) % calcSyntaxTree(node->rchild);
	}
  }

  return ERROR;
}
