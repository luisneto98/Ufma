#ifndef SYNTAX_TREE
#define SYNTAX_TREE

typedef enum { NUMBER, OPERATOR } typeNode;	

typedef struct _syntaxtree_{
	int data;
	typeNode type;
	struct _syntaxtree_ *lchild, *rchild;
} syntaxTree;

syntaxTree *createSyntaxNode(int data, typeNode type);
void lChild(syntaxTree *node, syntaxTree *child);
void rChild(syntaxTree *node, syntaxTree *child);
//void changeData(syntaxTree *node, int data);
int calcSyntaxTree(syntaxTree *node);

#else

typedef enum typeNode;	

typedef struct _syntaxtree_ syntaxTree;

extern syntaxTree *createSyntaxNode(int data, typeNode type);
extern void lChild(syntaxTree *node, syntaxTree *child);
extern void rChild(syntaxTree *node, syntaxTree *child);
//extern void changeData(syntaxTree *node, int data);
extern int calcSyntaxTree(syntaxTree *node);

#endif
