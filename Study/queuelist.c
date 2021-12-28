//queue used linked_list
//큐의 FIFO를 생각하며 연결리스트를 구성하자
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue
{
    int value;
    struct queue * next;
}queue;

queue* front = NULL;

bool isEmpty()
{
    if (front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(queue* head, int num) //stack의 push와 같은 역할
{

    queue* newqueue1 = (queue*)malloc(sizeof(queue));  //노드 생성  . newqueue1 은 추가 할 새로운 노드
    newqueue1->value = num; //노드 값 추가
   
    head->next = newqueue1;//head에 노드 연결 . newqueue1자체에도 주소값이 존재한다
   
    if (isEmpty())  //FIFO 이므로 front가 중요
    {
        front = newqueue1;
       
    }
    
}

int dequeue(queue *head) //stack의 pop과 같은 역할

{
    if (!isEmpty())
    {
        int ret=0;
        queue* remove = front; //remove 해줄 노드를 front로 지정 항상 FIFO 생각
        head->next = front->next; // 노드 연결 바꾸기
        ret = remove->value; // int형 변수를 return해줘야한다.
        free(remove);
        front = head->next;
        
        return ret;
    }
    else
    {
        printf("queue is empty!");
            return -1;
    }
}

void peek()
{
    printf("%d\n", front->value);
}

int main()
{
    int num = 0;
    queue* head = (queue*)malloc(sizeof(queue)); //헤드 노드 생성한다
    memset(head, NULL, sizeof(queue));
    queue* loc = head; // loc가 head를 가리킴

    for (int i = 0; i < 3; i++)
    {
        printf("넣을 값 입력 : ");
        scanf_s("%d", &num, sizeof(int));
        enqueue(loc, num);
        peek();
        head = head->next;
        loc = loc->next; //loc의  다음 노드 가르키기
    }

    for (int i = 0; i < 3; i++)
    {
        peek(); //printf뒤로 주면 끝난 뒤엔 남은 노드가 없으니까 볼 수가 없어 오류가 남
        printf("dequeue : %d\n", dequeue(head));
       
    }
}