//문제:  C 언어를 이용하여  하노이 탑을 쌓은  알고리즘을  프로그래밍.
//(1)  하노이탑 재귀 호출  알고리즘을  이용하여 프로그램




#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hanoi_tower(int n, char from, char temp, char to)
{
    if (n == 1)
        printf("원판 1가 %c에서 %c로 이동\n", from, to);
    else
    {
        hanoi_tower(n - 1, from, to, temp);
        printf("원판 %d가 %c에서 %c로 이동\n", n, from, to);
        hanoi_tower(n - 1, temp, from, to);
    }
}

void main()
{
    int n;
    printf("하노이탑 입력 : ");
    scanf("%d", &n);
    printf("");
        hanoi_tower(n, 'A', 'B', 'C');
}