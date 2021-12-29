
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

stack* top = NULL; //리스트의 헤드 기본값은 NULL


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

void push(stack* stk, int num) //데이터를 넣는다.
{
	
	stack *inputstk1 = (stack*)malloc(sizeof(stack)); //데이터 저장 노드 생성 . 동적 할당
	inputstk1->value = num; //새로운 노드에 값을 넣어줌
	inputstk1->ptr = stk->ptr; //stack에서는 LIFO이기 때문에 새로운 노드가 들어올 때, 
	                           //head와 원래 있던 노드 사이에 들어가야 하기에 연결해줌
	stk->ptr = inputstk1; //새로운 노드를  헤드 노드에 연결
	top = inputstk1; // 헤드연결
	

}

int pop(stack* stk) //데이터를 빼낸다.
{
	if (!isEmpty())
	{
		int ret = 0; // 변수 선언
		stack* remove; //제거해줄 노드
		remove = stk->ptr; // 삭제할 노드를 정한 것. 헤드 다음 노드가 제거해줄 노드니까
		top = stk->ptr->ptr; // 헤드가 노드의 다음다음을 가르켜야함 삭제 후 연결 해줘야함
		stk->ptr = stk->ptr->ptr; // 헤드 노드와 삭제할 노드의 다음 노드를 연결하여야, 중간 노드가 삭제되어도 나머지 노드들을 찾아갈 수 있기때문에
		                          // 해당 코드로 헤드 노드와 삭제할 노드의 다음 노드를 연결함
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
	stack* stk = (stack*)malloc(sizeof(stack)); //헤드노드 생성
	memset(stk, NULL, sizeof(stack));
	for (int i = 0; i<3; i++)
	{
		printf("넣을 값 입력 : ");
		scanf_s("%d", &num, sizeof(int));
		push(stk, num);
		peek();
	}
	for (int i = 0; i<3; i++)
	{
		printf("%d\n", pop(stk));
	}
}