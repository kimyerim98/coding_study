//ť
#include <stdio.h>
int location = -1;  //���� �ֱ� ��


void push(int* arr, int input_value) {  //�ִ°�
	location++; // ��ġ�� �÷�����
	arr[location] = input_value; // �÷������� ���� �־�����

}

void peek(int* arr) { //���°�
	printf("��: %d\n", arr[location]);

}

int pop(int* arr) {//���°�
	int output_value = arr[0]; //
	arr[0] = 0; 
	
	for (int i = 1; i <= location; i++) {

		arr[i - 1] = arr[i];
	}

	location--; // ��ġ�� �ٿ�����

	return output_value; //���� ��������
	
}


int main() { //321 321
	int arr[3] = { 0, };
	push(arr, 1);
	push(arr, 2);
	push(arr, 3);
	peek(arr);
	printf("%d\n", location);
	int a = pop(arr);
	printf("%d\n", a);
	peek(arr);
	printf("%d\n", location);

}

//FIFO 



