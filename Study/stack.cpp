//����
//pop�� ���°�
//peek�� ���°�
//push �ִ°�

#include <stdio.h>
int location = -1;  //���� �ֱ� ��


void push(int* arr , int input_value) {  //���� �ִ´�
	location++; // ��ġ�� �÷�����
	arr[location] = input_value; // �÷������� ���� �־�����

}

void peek(int* arr) { //���°�
	printf("��: %d\n", arr[location]);
	
}

int pop(int* arr) { //���� ����
	int output_value = arr[location]; // ���� ���� ����������
	arr[location] = 0; // ���� �ʱ�ȭ 
	location--; // ��ġ�� �ٿ�����
	return output_value; //���� ��������

}


int main() { //321 321
	int arr[3] = { 0, };
	push(arr, 1);
	push(arr, 2);
	push(arr, 3);
	peek(arr);
	int a = pop(arr);
	printf("%d\n", a);
	peek(arr);

}

//FILO 

