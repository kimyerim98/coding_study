#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Bi_Tree //tree
{
    int data;
    struct Bi_Tree* left; //���� �ڽ�
    struct Bi_Tree* right; //������ �ڽ�
}Bi_Tree;

Bi_Tree* root = NULL;

Bi_Tree* Insert_Node(Bi_Tree* r_node, int num) //��� ����
{
    if (r_node == NULL)
    {
        Bi_Tree* r_Node = (Bi_Tree*)malloc(sizeof(Bi_Tree)); //��� ����
        memset(r_Node, NULL, sizeof(r_Node)); //������ ��� �ʱ�ȭ
        r_Node->data = num;//��� ������ ����
        r_Node->left = NULL;//��� �ʱ�ȭ
        r_Node->right = NULL;//��� �ʱ�ȭ
        return r_Node;
    }
    if (r_node->data > num) // ���� �� ��������
    {
        r_node->left = Insert_Node(r_node->left, num); // ����� ���� ��带 ������, ������
    }
    if (r_node->data < num) //Ŭ �� ���������� 
    {
        r_node->right = Insert_Node(r_node->right, num); //����� ������ ��带 ������, ������
    }


    return r_node;
}

void preorderPrint(Bi_Tree* root) { //������ȸ (root->����->������)
    if (root != NULL) {
        printf("%d", root->data);
        preorderPrint(root->left);
        preorderPrint(root->right);

    }
}

void inorderPrint(Bi_Tree* root) { //������ȸ (����->root->������)
    if (root != NULL) {
        inorderPrint(root->left);
        printf("%d", root->data);
        inorderPrint(root->right);

    }
}

void postorderPrint(Bi_Tree* root) { //������ȸ (����->������->root)
    if (root != NULL) {
        postorderPrint(root->left);
        postorderPrint(root->right);
        printf("%d", root->data);
    }
}


int main()
{


    int value[10] = { 4,6,3,2,1,7,5,8,9,10 };
    for (int i = 0; i < 10; i++)
    {
        root = Insert_Node(root, value[i]);
    }

    inorderPrint(root);
}

//