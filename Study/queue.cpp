//큐
#include <stdio.h>
int location = -1;  //가장 최근 값


void push(int* arr, int input_value) {  //넣는거
	location++; // 위치를 늘려주자
	arr[location] = input_value; // 늘려줬으니 값을 넣어주자

}

void peek(int* arr) { //보는거
	printf("값: %d\n", arr[location]);

}

int pop(int* arr) {//뺴는거
	int output_value = arr[0]; //
	arr[0] = 0; 
	
	for (int i = 1; i <= location; i++) {

		arr[i - 1] = arr[i];
	}

	location--; // 위치를 줄여주자

	return output_value; //값을 빼내주자
	
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



