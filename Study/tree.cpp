#include<stdio.h>
#include<stdlib.h>

typedef struct Tnode
{
	struct Tnode* root;
	int data;
	struct Tnode* left;
	struct Tnode* right;

}Tnode;

Tnode* root; //헤드노드

//새로운 노드 추가하는 함수 만들어줌

//
void insert(Tnode*loc ,int num) {
	Tnode* n1 = (Tnode*)malloc(sizeof(Tnode));
	Tnode* n2 = (Tnode*)malloc(sizeof(Tnode));
	Tnode* n3 = (Tnode*)malloc(sizeof(Tnode));

	n1->data = 10;
	n1->left = n2;
	n1->right = n3;
	n2->data = 5;
	n2->left = NULL;
	n2->right = NULL;
	n3->data = 30;
	n3->left = NULL;
	n3->right = NULL;
	if (loc == NULL)
	{
		loc->data = num;
	}
	else {
		if (num<loc->data)
			loc->left = loc->root;
		else
			loc->right = loc->root;
	}
}
int main() {
	//inorderPrint 중위
	
	
}