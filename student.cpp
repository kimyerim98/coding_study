//��ǻ�Ͱ��а� 3�г��� �̹� �б� ���� ���л� ������ ���ؼ� 25���� �л���
//����� 1�� - 10������ ã�� ���� ����ϰ�, �� �Ʒ��� ���� �Է°� ��� ���Ŀ� �°� ���α׷��� �Ͻÿ�.


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STD 25 //25���� �л��� ������� ����ü

struct Stu
{
	int sid;
	char name[16];
	int os,cs,bd,ml;
	int total;
	float avg;
	int rank;

};

void main()
{
	Stu stu[MAX_STD];
	int i,j;
	
	memset(stu, sizeof(stu), 0); //���� �ʱ�ȭ

	printf("�л� ������ �Է��Ͻÿ� \n");

	for (i = 0; i < MAX_STD; i++) //for���� �̿��� 25���� ������ ��� �Է� �޾��ش�
	{
		printf("�й�\t�̸�\t�ü��\t��ǻ�ͱ���\t�����ͽǹ�\t����Ͼ�� : \n");
		scanf("%d %s %d %d %d %d", &stu[i].sid, stu[i].name, &stu[i].os, &stu[i].cs, &stu[i].bd, &stu[i].ml); //int�� &���� �Ҵ�

		stu[i].total = stu[i].os + stu[i].cs + stu[i].bd + stu[i].ml; //������ ��� ������ ���Ѱ�
		stu[i].avg = (float)stu[i].total / 4; //����� ���ճ����� �����
	}
	for (i = 0; i < MAX_STD; i++)  
	{
		stu[i].rank = 1;
		
		for (j = 0; j < MAX_STD; j++)
		{
			if (stu[j].avg > stu[i].avg) //����� ���Ѵ�
			{
				stu[i].rank++;//����� ���ؼ� ������� �����Ѵ�
			}

			else if (stu[j].avg == stu[i].avg) // ����� ������
			{
				if (stu[j].total > stu[i].total) //�հ�� ���Ѵ�
				{
					stu[i].rank++; 
				}
				else if (stu[j].sid < stu[i].sid) //�й��� �������� �� �켱�� �ȴ�
				{
					if (stu[j].sid < stu[i].sid)
					{
						stu[i].rank++;
					}
				}
				
			}
		}


	}
	printf("------------------------------------------------------------------------------\n");
	printf("���� �й� �̸� �ü�� ��ǻ�ͱ��� �����ͽǹ� ����Ͼ�� �հ� ���\n");
	printf("------------------------------------------------------------------------------\n");


	for (i = 1; i<11; i++)
	{
		for (j = 0;j < 25;j++)
		{
			if (i==stu[j].rank)
				printf("%d\t%d\t%s\t%d\t%d\t%d\t%d\t%d\t%.1f\n", stu[j].rank, stu[j].sid, stu[j].name, stu[j].os, stu[j].cs, stu[j].bd, stu[j].ml, stu[j].total, stu[j].avg);

		}
	}

}
//1.  �Է� ������ ����
//��  ��  ��  ��   �ü��os ��ǻ�ͱ���cs �����ͽǹ�bd  ����� ���ml
//9�ڸ�   15�ڸ�    3�ڸ�     3�ڸ�        3�ڸ�          3�ڸ�


//2.  ��� ��� ����
//��  ��  ��  ��  �ü��  ��ǻ�ͱ��� ������  ����Ͼ��  ��  ��  ��  ��  �� ��
//9�ڸ�   15�ڸ�   3�ڸ�     3�ڸ�     3�ڸ�       3�ڸ�    3�ڸ�   4�ڸ�   2�ڸ�

//* ����� �Ҽ��� ���� ���ڸ����� ���
//�� ����� ������ �ÿ��� �հ�� �켱 ������ �켱 ���
//�� ����� ������ �ÿ��� �й��� ���� ������ �켱 ���
