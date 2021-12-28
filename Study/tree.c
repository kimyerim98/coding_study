#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Bi_Tree //tree
{
	struct Bi_Tree* root; //�θ� ���
	int data; 
	unsigned int degree;
	struct Bi_Tree* left; //���� �ڽ�
	struct Bi_Tree* right; //������ �ڽ�
}Bi_Tree;

void Insert_Node(Bi_Tree* root, int num)
{
	bool is_left = false; //�갡 �������� Ȯ���ϴ� bool ���� while���� ������, ����ʿ� �پ���ϴ��� �˼��־�.
	if (root->data == NULL) 
	{
		root->data = num; //root�� ��������� root�� ������ �Է�
		root->left = NULL;
		root->right = NULL;

	}
	else
	{
		Bi_Tree* Node = (Bi_Tree*)malloc(sizeof(Bi_Tree)); //��� ����
		memset(Node, NULL, sizeof(Node)); //������ ��� �ʱ�ȭ
		Node->data = num; //��忡 ������ �Է�
		while (root != NULL) //root�� NULL�̸� ����
		{
			if (root->data > Node->data) //���ο� �����Ͱ� ������ //���� ���� �������� 
			{
				root = root->left; //�������� ����


			}
			else //���ο� �����Ͱ� Ŭ�� // ũ�� ����������
			{
				root = root->right; //���������� ����

			}
		}
		//���� ���� ������  
		if (is_left) //��������
		{
			root->left = Node; //�����̸� ���ο� ��带 ���ʿ� �־��ش�
			root = root->root;


		}
		else //����������
		{
			root->right = Node; //�������̸� ���ο� ��带 �����ʿ� �־��ش�.
			root = root->root;

		}
	}

}

void inorder_print()
{

}

int main()
{
	Bi_Tree* root = (Bi_Tree*)malloc(sizeof(Bi_Tree)); //root ����
	memset(root, NULL, sizeof(root)); //root �ʱ�ȭ
	int data[10] = { 4,6,3,2,1,7,5,8,9,10 };
	for (int i = 0; i<10; i++)
	{
		Bi_Tree* loc = root; // root���� �����ϱ� ���ؼ�
		Insert_Node(loc, data); 
	}
}