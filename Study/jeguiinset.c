#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Bi_Tree //tree
{
    int data;
    struct Bi_Tree* left; //왼쪽 자식
    struct Bi_Tree* right; //오른쪽 자식
}Bi_Tree;

Bi_Tree* root = NULL;

Bi_Tree* Insert_Node(Bi_Tree* r_node, int num) //노드 생성
{
    if (r_node == NULL)
    {
        Bi_Tree* r_Node = (Bi_Tree*)malloc(sizeof(Bi_Tree)); //노드 생성
        memset(r_Node, NULL, sizeof(r_Node)); //생성한 노드 초기화
        r_Node->data = num;//노드 데이터 삽입
        r_Node->left = NULL;//노드 초기화
        r_Node->right = NULL;//노드 초기화
        return r_Node;
    }
    if (r_node->data > num) // 작을 때 왼쪽으로
    {
        r_node->left = Insert_Node(r_node->left, num); // 노드의 왼쪽 노드를 연결함, 증감식
    }
    if (r_node->data < num) //클 때 오른쪽으로 
    {
        r_node->right = Insert_Node(r_node->right, num); //노드의 오른쪽 노드를 연결함, 증감식
    }


    return r_node;
}

void preorderPrint(Bi_Tree* root) { //전위순회 (root->왼쪽->오른쪽)
    if (root != NULL) {
        printf("%d", root->data);
        preorderPrint(root->left);
        preorderPrint(root->right);

    }
}

void inorderPrint(Bi_Tree* root) { //중위순회 (왼쪽->root->오른쪽)
    if (root != NULL) {
        inorderPrint(root->left);
        printf("%d", root->data);
        inorderPrint(root->right);

    }
}

void postorderPrint(Bi_Tree* root) { //후위순회 (왼쪽->오른쪽->root)
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