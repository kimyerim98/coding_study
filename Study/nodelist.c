#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct PD
{
	int data;
	struct PD* next; //��ġ�� ��Ÿ���ֱ� ���� ��. 
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
	PD* pd = (PD*)malloc(sizeof(PD));  //��� ����
	int data2 = 0;

	scanf("%d", &data2);
	PD* insert1 = (PD*)malloc(sizeof(PD));  //���1 ����
	insert1->data = data2; //���1�� �� �ֱ�
	pd->next = insert1; //���� ���1 �̾��ֱ�

	scanf("%d", &data2);
	PD* insert2 = (PD*)malloc(sizeof(PD)); //���2 ����
	insert2->data = data2; //���2�� �� �ֱ�
	insert1->next = insert2; //���2�� ���1 �̾��ֱ�


	scanf("%d", &data2); 
	PD* insert3 = (PD*)malloc(sizeof(PD));  //���3����
	insert3->data = data2;  //���3�� �� �ֱ�
	insert2->next = insert3; //���3�̶� ���2 �̾��ֱ�


	insert3->next = NULL;  //���3 �ڴ� ����ش�

	print(pd);

	return 0;


}