#include<stdio.h>
//(x-1)/2
void heap(int temp[], int num) {
    for (int i = 1; i < num; i++) {
        int child=i;
       
        int root = child  / 2; //�ڽ� ��忡�� ����ϸ� �θ��尡 ���´�
        if (temp[root] < temp[child]) { //�ڽ� ��尡 �θ��庸�� ũ�� ��ȯ�Ѵ�.
            int a = temp[root];
            temp[root] = temp[child];
            temp[child] = a;
        }
    }
}

int main() {
    int data[] = { 29,1,5,9,3,17,6,7,5,10 }; //10��
    heap(data, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", data[i]); //���
    }

}