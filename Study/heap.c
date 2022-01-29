#include<stdio.h>
//(x-1)/2
void heap(int temp[], int num) {
    for (int i = 1; i < num; i++) {
        int child=i;
       
        int root = child  / 2; //자식 노드에서 계산하면 부모노드가 나온다
        if (temp[root] < temp[child]) { //자식 노드가 부모노드보다 크면 교환한다.
            int a = temp[root];
            temp[root] = temp[child];
            temp[child] = a;
        }
    }
}

int main() {
    int data[] = { 29,1,5,9,3,17,6,7,5,10 }; //10개
    heap(data, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", data[i]); //출력
    }

}