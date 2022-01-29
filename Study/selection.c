#include<stdio.h>

int main()
{
	int array[10] = { 1,10,5,8,7,6,4,3,2,9 };
	
	int temp;
	for (int i = 0;i < 10; i++) {
		int min = i;
		for (int j = i;j < 9;j++) {
			if (array[min] > array[j + 1]) {
				min = array[j + 1];
				min = j + 1;
				
			}
		}
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}

	for (int i = 0; i < 10; i++)
	{
		printf(" %d ", array[i]);
	}
}

