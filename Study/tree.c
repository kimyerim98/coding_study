#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Bi_Tree //tree
{
	struct Bi_Tree* root; //부모 노드
	int data; 
	unsigned int degree;
	struct Bi_Tree* left; //왼쪽 자식
	struct Bi_Tree* right; //오른쪽 자식
}Bi_Tree;

void Insert_Node(Bi_Tree* root, int num)
{
	bool is_left = false; //얘가 왼쪽인지 확인하는 bool 변수 while문이 끝나고, 어느쪽에 붙어야하는지 알수있어.
	if (root->data == NULL) 
	{
		root->data = num; //root가 비어있으니 root에 데이터 입력
		root->left = NULL;
		root->right = NULL;

	}
	else
	{
		Bi_Tree* Node = (Bi_Tree*)malloc(sizeof(Bi_Tree)); //노드 생성
		memset(Node, NULL, sizeof(Node)); //생성한 노드 초기화
		Node->data = num; //노드에 데이터 입력
		while (root != NULL) //root가 NULL이면 종료
		{
			if (root->data > Node->data) //새로운 데이터가 작을때 //작을 때는 왼쪽으로 
			{
				root = root->left; //왼쪽으로 ㄱㄱ


			}
			else //새로운 데이터가 클때 // 크면 오른쪽으로
			{
				root = root->right; //오른쪽으로 ㄱㄱ

			}
		}
		//이전 노드로 돌리기  
		if (is_left) //왼쪽인지
		{
			root->left = Node; //왼쪽이면 새로운 노드를 왼쪽에 넣어준다
			root = root->root;


		}
		else //오른쪽인지
		{
			root->right = Node; //오른쪽이면 새로운 노드를 오른쪽에 넣어준다.
			root = root->root;

		}
	}

}

void inorder_print()
{

}

int main()
{
	Bi_Tree* root = (Bi_Tree*)malloc(sizeof(Bi_Tree)); //root 생성
	memset(root, NULL, sizeof(root)); //root 초기화
	int data[10] = { 4,6,3,2,1,7,5,8,9,10 };
	for (int i = 0; i<10; i++)
	{
		Bi_Tree* loc = root; // root부터 시작하기 위해서
		Insert_Node(loc, data); 
	}
}