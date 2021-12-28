/*문제 : 1000년부터 2021년까지 윤달이 있는 해의 합의 결과와 평년의 합의 결과,
      윤달이 있는 해가 몇 개인지 그 결과를  출력하시오.

 윤달 : 역법과 실제 우주년 또는 계절년을 맞추기 위해 여분의 날이나 달을 끼우는 달.
지구의 공전주기는 365.2422일, 1달(1삭망월)는 29.53일 즉, 365.2422/29.53 = 12.36851337622757가 된다. 여기서, 소수점 부분이 중첩되면, 1을 넘기 때문에 이를 추가하는 것이 윤달.
7년 동안 19번의 윤달이 와야함.*/

#include <stdio.h>
#include <string.h>
#define Year_To_Month 12 //1년을 해로 바꿨을 때
#define Earth_Cycle 365.2422 //지구의 공전주기
#define Moon_Cycle 29.53 // 1달(1 삭망월)

typedef struct Leap
{
    int Leap_Month_sum; //윤달이 있는 해의 합
    int Leap_Month_count; //윤달이 있는 해의 개수
    int Common_Year_sum; //평년의 합
    double ID_leap; //윤달인지 확인하기 위한 변수
    double Remain_month; //윤달을 만들기 위한 변수

}Leap;



int main()
{
    Leap Leap;
    memset(&Leap, 0, sizeof(Leap)); //Struct reset 0
    Leap.Remain_month = (Earth_Cycle / Moon_Cycle) - Year_To_Month;


    for (int i = 0; i < 2022; i++) //AD 1000 ~ AD 2021
    {
        Leap.ID_leap += Leap.Remain_month; //해가 지나며 남은 날을 더한다.

        if (i % 4 != 0 || i % 4 == 0 && i % 100 == 0) //평년
        {
            if (Leap.ID_leap > 1) //윤달일 때
            {
                if (i >= 1000)
                {
                    Leap.Leap_Month_count++; //윤달 개수 증가
                    Leap.Leap_Month_sum += i; //윤달인 해의 합 증가
                }
                Leap.ID_leap = Leap.ID_leap - 1; // 윤달 추가했기 때문에 줄인다.
            }

            if (i >= 1000)
            {
                Leap.Common_Year_sum += i; //평년 증가
            }
        }

        else if (i % 4 == 0) //윤년
        {
            if (Leap.ID_leap > 1) //윤달일 때
            {
                if (i >= 1000)
                {
                    Leap.Leap_Month_count++; //윤달 개수 증가
                    Leap.Leap_Month_sum += i; //윤달인 해의 합 증가
                }
                Leap.ID_leap = Leap.ID_leap - 1; // 윤달 추가했기 때문에 줄인다.
            }

            if (i % 100 == 0 && i >= 1000) //4로 나누어떨어지면서 100으로도 나누어 떨어질 때는 평년
            {
                if (i % 400 != 0) // 4, 100, 400으로 나누어 떨어지면 윤년이기 때문에 한번 더 확인
                {
                    Leap.Common_Year_sum += i;
                }

            }

        }

    }

    printf("윤달인 해의 개수 : %d\n", Leap.Leap_Month_count);
    printf("윤달인 해의 합 : %d\n", Leap.Leap_Month_sum);
    printf("평년인 해의 합 : %d\n", Leap.Common_Year_sum);

    return 0;
}