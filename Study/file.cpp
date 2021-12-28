#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STD 11 //11��

struct Stu //����ü �迭
{
    char name[10]; //�̸�
    char ad[100]; //�ּ� 
    char ph[15]; //�ڵ���
    char fu[30]; //���λ���
    char sp[100]; //Ư�̻���
};
void save(struct Stu stu[], FILE* fp) {  //void save(����ü �迭, ����������)
    fp = fopen("test.txt", "w"); //������������ ������ �����ش�
    int a;

    if (fp == NULL) { //������ ����� ���ȴ��� �˻�
        printf("���� \n"); //���������Ͱ� ������ ������ NULL���� ������
        return;
    }
    else if (fp != NULL) {
        for (a = 0; a < MAX_STD; a++) {  //������ ���� for�� ���

            fprintf(fp, "%s", (stu + a)->name); //fprintf�� ���Ͽ� �����͸� �ֱ����� ���
            fprintf(fp, "%s", (stu + a)->ad);
            fprintf(fp, "%s", (stu + a)->ph);
            fprintf(fp, "%s", (stu + a)->fu);
            fprintf(fp, "%s", (stu + a)->sp);

        }

    }
    fclose(fp); //����������� �Ϸ��ϸ� ���ݾ�����

}

void addStu(struct Stu stu[]) {
    int a;

    //�Է�

    for (a = 0; a < MAX_STD; a++) {
        printf("�� �߰��� �����͸�  �Է��ϼ���.\n");
        printf("+==========================+\n");
        printf("�̸� : ");
        fputc(0, stdin); //��Ʈ���� stdin
        fgets((stu + a)->name, sizeof((stu + a)->name), stdin);
        printf("�ּ� : ");
        fputc(0, stdin);
        getchar(); //�Է¹��� ����
        fgets((stu + a)->ad, sizeof((stu + a)->ad), stdin);
        printf("����ó : ");
        fputc(0, stdin);
        fgets((stu + a)->ph, sizeof((stu + a)->ph), stdin);
        printf("���λ��� : ");
        fputc(0, stdin);
        fgets((stu + a)->fu, sizeof((stu + a)->fu), stdin);
        printf("Ư�̻��� : ");
        fgets((stu + a)->sp, sizeof((stu + a)->sp), stdin);
    }

    //���

    printf("+==========================+\n");
    printf("������Ʈ�� ���\n");
    for (a = 0; a < MAX_STD; a++) {
        printf("�̸� : ");
        printf("%s", (stu + a)->name);
        printf("�ּ� : ");
        printf("%s", (stu + a)->ad);
        printf("����ó : ");
        printf("%s", (stu + a)->ph);
        printf("���λ��� : ");
        printf("%s", (stu + a)->fu);
        printf("Ư�̻��� : ");
        printf("%s", (stu + a)->sp);

    }

}
void modifyStu(struct Stu stu[]) {

    char num[10];
    int a;

    printf("�˻��� �л��� �̸� : ");
    fputc(0, stdin);
    fgets(num, sizeof(num), stdin);
    for (a = 0; a < MAX_STD; a++) {
        if (strcmp(num, (stu + a)->name) == 0) {
            printf("�� �߰��� �����͸�  �Է��ϼ���.\n");
            printf("+==========================+\n");
            printf("�̸� : ");
            fputc(0, stdin);
            fgets((stu + a)->name, sizeof((stu + a)->name), stdin);
            printf("�ּ� : ");
            fputc(0, stdin);
            getchar();
            fgets((stu + a)->ad, sizeof((stu + a)->ad), stdin);
            printf("����ó : ");
            fputc(0, stdin);
            fgets((stu + a)->ph, sizeof((stu + a)->ph), stdin);
            printf("���λ��� : ");
            fputc(0, stdin);
            fgets((stu + a)->fu, sizeof((stu + a)->fu), stdin);
            printf("Ư�̻��� : ");
            fgets((stu + a)->sp, sizeof((stu + a)->sp), stdin);

        }
    }
}
void searchStu(struct Stu stu[]) {

    char num[10] = { 0, };
    int a;

    printf("�˻��� �л��� �̸� : ");
    fputc(0, stdin);
    fgets(num, sizeof(num), stdin);
    for (a = 0; a < MAX_STD; a++) {

        if (strcmp(num, (stu + a)->name) == 0) {
            printf("�̸� : ");
            printf("%s", (stu + a)->name);
            printf("�ּ� : ");
            printf("%s", (stu + a)->ad);
            printf("����ó : ");
            printf("%s", (stu + a)->ph);
            printf("���λ��� : ");
            printf("%s", (stu + a)->fu);
            printf("Ư�̻��� : ");
            printf("%s", (stu + a)->sp);

        }
    }

}
void load(struct Stu stu[], FILE* fp) {
    fp = fopen("test.txt", "r");
    int a = 0;

    if (fp == NULL) {
        printf("���� \n");
        return;
    }
    else if (fp != NULL) {

        while (1) {
            fgets((stu + a)->name, sizeof((stu + a)->name), fp);
            fgets((stu + a)->ad, sizeof((stu + a)->ad), fp);
            fgets((stu + a)->ph, sizeof((stu + a)->ph), fp);
            fgets((stu + a)->fu, sizeof((stu + a)->fu), fp);
            fgets((stu + a)->sp, sizeof((stu + a)->sp), fp);
            a++;
            if (feof(fp))break;    //������ ���� �������� �����ϸ� Ż��
        }

    }
    fclose(fp);

}


int main()
{
    int i = 0;
    struct Stu stu[25];
    FILE* fp = NULL;  //���������� ����

    load(stu, fp);

    while (1) {
        printf("+= ======================== = +\n");
        printf("1.�߰�\n");
        printf("2.����\n");
        printf("3.�˻�\n");
        printf("4.����\n");
        printf("+= ======================== = +\n");
        printf("�������� �Է��Ͻÿ�\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            getchar();
            addStu(stu);
            break;
        case 2:
            getchar();
            modifyStu(stu);
            break;
        case 3:
            getchar();
            searchStu(stu);
            break;
        case 4:
            save(stu, fp);
            return 0;
        default:

            for (int a = 0; a < MAX_STD; a++)
            {
                printf("%s\n%s\n%s\n%s\n%s\n", stu[a].name, stu[a].ad, stu[a].ph, stu[a].fu, stu[a].sp);
            }
            break;

        }

    }
    return 0;

}


//1. ��ǻ�Ͱ��а� 4�г� ������� ������  ������ �Է��ϰų� �������� �Ҽ� �ִ� ������ ���α׷��̴�.
//2. �Է��ϰų� ���������� �����ʹ� ���Ϸ� �����Ѵ�.
//(������ ������ ���̽���� �ϰڴ�)
//3. �� ����� �����ʹ� �˻��� �� �ִ�.
//4. ����ó �����ʹ� ����ü�� ����ؼ� ������ �����Ѵ�.
//5. ȭ������ ������ �Է��� ���� �޴��� �������͵� �޴��� �Ʒ��� ����.
//6. �Է� �����ʹ� 10�� �̻�
//7. ���� ���
//(1) ������ �Է��� ���� �޴�
//+= ======================== = +
//1. �߰� :
//2. ���� :
  //  3. �˻� :
    //4. ����
   // += ======================== = +

    //�������� �Է��ϼ��� : 1
//�̸�, �ּ�, ����ó, ���λ���, Ư�̻���