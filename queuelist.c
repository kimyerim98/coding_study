//queue used linked_list
//ť�� FIFO�� �����ϸ� ���Ḯ��Ʈ�� ��������
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

void enqueue(queue* head, int num) //stack�� push�� ���� ����
{

    queue* newqueue1 = (queue*)malloc(sizeof(queue));  //��� ����  . newqueue1 �� �߰� �� ���ο� ���
    newqueue1->value = num; //��� �� �߰�
   
    head->next = newqueue1;//head�� ��� ���� . newqueue1��ü���� �ּҰ��� �����Ѵ�
   
    if (isEmpty())  //FIFO �̹Ƿ� front�� �߿�
    {
        front = newqueue1;
       
    }
    
}

int dequeue(queue *head) //stack�� pop�� ���� ����

{
    if (!isEmpty())
    {
        int ret=0;
        queue* remove = front; //remove ���� ��带 front�� ���� �׻� FIFO ����
        head->next = front->next; // ��� ���� �ٲٱ�
        ret = remove->value; // int�� ������ return������Ѵ�.
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
    queue* head = (queue*)malloc(sizeof(queue)); //��� ��� �����Ѵ�
    memset(head, NULL, sizeof(queue));
    queue* loc = head; // loc�� head�� ����Ŵ

    for (int i = 0; i < 3; i++)
    {
        printf("���� �� �Է� : ");
        scanf_s("%d", &num, sizeof(int));
        enqueue(loc, num);
        peek();
        head = head->next;
        loc = loc->next; //loc��  ���� ��� ����Ű��
    }

    for (int i = 0; i < 3; i++)
    {
        peek(); //printf�ڷ� �ָ� ���� �ڿ� ���� ��尡 �����ϱ� �� ���� ���� ������ ��
        printf("dequeue : %d\n", dequeue(head));
       
    }
}