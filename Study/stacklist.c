
//new node ->next  = old node

//Stack usud linkedlist

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack
{
	int value;
	struct stack* ptr;
}stack;

stack* top = NULL; //����Ʈ�� ��� �⺻���� NULL


bool isEmpty()
{
	if (top == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void push(stack* stk, int num) //�����͸� �ִ´�.
{
	
	stack *inputstk1 = (stack*)malloc(sizeof(stack)); //������ ���� ��� ���� . ���� �Ҵ�
	inputstk1->value = num; //���ο� ��忡 ���� �־���
	inputstk1->ptr = stk->ptr; //stack������ LIFO�̱� ������ ���ο� ��尡 ���� ��, 
	                           //head�� ���� �ִ� ��� ���̿� ���� �ϱ⿡ ��������
	stk->ptr = inputstk1; //���ο� ��带  ��� ��忡 ����
	top = inputstk1; // ��忬��
	

}

int pop(stack* stk) //�����͸� ������.
{
	if (!isEmpty())
	{
		int ret = 0; // ���� ����
		stack* remove; //�������� ���
		remove = stk->ptr; // ������ ��带 ���� ��. ��� ���� ��尡 �������� ���ϱ�
		top = stk->ptr->ptr; // ��尡 ����� ���������� �����Ѿ��� ���� �� ���� �������
		stk->ptr = stk->ptr->ptr; // ��� ���� ������ ����� ���� ��带 �����Ͽ���, �߰� ��尡 �����Ǿ ������ ������ ã�ư� �� �ֱ⶧����
		                          // �ش� �ڵ�� ��� ���� ������ ����� ���� ��带 ������
		ret = remove->value; //   
		free(remove);
		return ret;
	}
	else
	{
		printf("stack is Empty!\n");
		return -1;
	}
}


void peek()
{
	printf("%d\n", top->value);
}

int main()
{
	int num = 0;
	stack* stk = (stack*)malloc(sizeof(stack)); //����� ����
	memset(stk, NULL, sizeof(stack));
	for (int i = 0; i<3; i++)
	{
		printf("���� �� �Է� : ");
		scanf_s("%d", &num, sizeof(int));
		push(stk, num);
		peek();
	}
	for (int i = 0; i<3; i++)
	{
		printf("%d\n", pop(stk));
	}
}