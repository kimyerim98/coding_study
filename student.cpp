//컴퓨터공학과 3학년의 이번 학기 성적 장학생 선발을 위해서 25명의 학생중
//우수한 1위 - 10위까지 찾아 내어 출력하고, 또 아래와 같이 입력과 출력 형식에 맞게 프로그래밍 하시오.


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STD 25 //25명의 학생을 집어넣을 구조체

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
	
	memset(stu, sizeof(stu), 0); //변수 초기화

	printf("학생 정보를 입력하시오 \n");

	for (i = 0; i < MAX_STD; i++) //for문을 이용해 25명의 정보를 모두 입력 받아준다
	{
		printf("학번\t이름\t운영체제\t컴퓨터구조\t빅데이터실무\t모바일언어 : \n");
		scanf("%d %s %d %d %d %d", &stu[i].sid, stu[i].name, &stu[i].os, &stu[i].cs, &stu[i].bd, &stu[i].ml); //int형 &으로 할당

		stu[i].total = stu[i].os + stu[i].cs + stu[i].bd + stu[i].ml; //총합은 모든 성적을 더한것
		stu[i].avg = (float)stu[i].total / 4; //평균은 총합나누기 과목수
	}
	for (i = 0; i < MAX_STD; i++)  
	{
		stu[i].rank = 1;
		
		for (j = 0; j < MAX_STD; j++)
		{
			if (stu[j].avg > stu[i].avg) //평균을 비교한다
			{
				stu[i].rank++;//평균을 비교해서 순위대로 나열한다
			}

			else if (stu[j].avg == stu[i].avg) // 평균이 같을때
			{
				if (stu[j].total > stu[i].total) //합계로 비교한다
				{
					stu[i].rank++; 
				}
				else if (stu[j].sid < stu[i].sid) //학번이 빠른순이 더 우선이 된다
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
	printf("순위 학번 이름 운영체제 컴퓨터구조 빅데이터실무 모바일언어 합계 평균\n");
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
//1.  입력 데이터 형식
//학  번  이  름   운영체제os 컴퓨터구조cs 빅데이터실무bd  모바일 언어ml
//9자리   15자리    3자리     3자리        3자리          3자리


//2.  출력 결과 형식
//학  번  이  름  운영체제  컴퓨터구조 빅데이터  모바일언어  합  계  평  균  순 위
//9자리   15자리   3자리     3자리     3자리       3자리    3자리   4자리   2자리

//* 평균은 소수점 이하 한자리까지 사용
//● 평균이 동점일 시에는 합계로 우선 순위로 우선 결과
//● 평균이 동점일 시에는 학번이 빠른 순으로 우선 결과
