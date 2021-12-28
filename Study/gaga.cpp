/*���� : 1000����� 2021����� ������ �ִ� ���� ���� ����� ����� ���� ���,
      ������ �ִ� �ذ� �� ������ �� �����  ����Ͻÿ�.

 ���� : ������ ���� ���ֳ� �Ǵ� �������� ���߱� ���� ������ ���̳� ���� ����� ��.
������ �����ֱ�� 365.2422��, 1��(1�����)�� 29.53�� ��, 365.2422/29.53 = 12.36851337622757�� �ȴ�. ���⼭, �Ҽ��� �κ��� ��ø�Ǹ�, 1�� �ѱ� ������ �̸� �߰��ϴ� ���� ����.
7�� ���� 19���� ������ �;���.*/

#include <stdio.h>
#include <string.h>
#define Year_To_Month 12 //1���� �ط� �ٲ��� ��
#define Earth_Cycle 365.2422 //������ �����ֱ�
#define Moon_Cycle 29.53 // 1��(1 �����)

typedef struct Leap
{
    int Leap_Month_sum; //������ �ִ� ���� ��
    int Leap_Month_count; //������ �ִ� ���� ����
    int Common_Year_sum; //����� ��
    double ID_leap; //�������� Ȯ���ϱ� ���� ����
    double Remain_month; //������ ����� ���� ����

}Leap;



int main()
{
    Leap Leap;
    memset(&Leap, 0, sizeof(Leap)); //Struct reset 0
    Leap.Remain_month = (Earth_Cycle / Moon_Cycle) - Year_To_Month;


    for (int i = 0; i < 2022; i++) //AD 1000 ~ AD 2021
    {
        Leap.ID_leap += Leap.Remain_month; //�ذ� ������ ���� ���� ���Ѵ�.

        if (i % 4 != 0 || i % 4 == 0 && i % 100 == 0) //���
        {
            if (Leap.ID_leap > 1) //������ ��
            {
                if (i >= 1000)
                {
                    Leap.Leap_Month_count++; //���� ���� ����
                    Leap.Leap_Month_sum += i; //������ ���� �� ����
                }
                Leap.ID_leap = Leap.ID_leap - 1; // ���� �߰��߱� ������ ���δ�.
            }

            if (i >= 1000)
            {
                Leap.Common_Year_sum += i; //��� ����
            }
        }

        else if (i % 4 == 0) //����
        {
            if (Leap.ID_leap > 1) //������ ��
            {
                if (i >= 1000)
                {
                    Leap.Leap_Month_count++; //���� ���� ����
                    Leap.Leap_Month_sum += i; //������ ���� �� ����
                }
                Leap.ID_leap = Leap.ID_leap - 1; // ���� �߰��߱� ������ ���δ�.
            }

            if (i % 100 == 0 && i >= 1000) //4�� ����������鼭 100���ε� ������ ������ ���� ���
            {
                if (i % 400 != 0) // 4, 100, 400���� ������ �������� �����̱� ������ �ѹ� �� Ȯ��
                {
                    Leap.Common_Year_sum += i;
                }

            }

        }

    }

    printf("������ ���� ���� : %d\n", Leap.Leap_Month_count);
    printf("������ ���� �� : %d\n", Leap.Leap_Month_sum);
    printf("����� ���� �� : %d\n", Leap.Common_Year_sum);

    return 0;
}