#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct PD
{
	int data;
	struct PD* next; //위치를 나타내주기 위한 것. 
}PD;

void print(PD* input) {
	PD* curr = input->next;
	while (curr != NULL) {
		printf("data=%d\n", curr->data);
		curr = curr->next;
	}
}



int main()
{
	PD* pd = (PD*)malloc(sizeof(PD));  //노드 생성
	int data2 = 0;

	scanf("%d", &data2);
	PD* insert1 = (PD*)malloc(sizeof(PD));  //노드1 생성
	insert1->data = data2; //노드1에 값 넣기
	pd->next = insert1; //헤드와 노드1 이어주기

	scanf("%d", &data2);
	PD* insert2 = (PD*)malloc(sizeof(PD)); //노드2 생성
	insert2->data = data2; //노드2에 값 넣기
	insert1->next = insert2; //노드2와 노드1 이어주기


	scanf("%d", &data2); 
	PD* insert3 = (PD*)malloc(sizeof(PD));  //노드3생성
	insert3->data = data2;  //노드3에 값 넣기
	insert2->next = insert3; //노드3이랑 노드2 이어주기


	insert3->next = NULL;  //노드3 뒤는 비어준다

	print(pd);

	return 0;


}