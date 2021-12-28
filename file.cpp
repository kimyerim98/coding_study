#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STD 11 //11명

struct Stu //구조체 배열
{
    char name[10]; //이름
    char ad[100]; //주소 
    char ph[15]; //핸드폰
    char fu[30]; //진로사항
    char sp[100]; //특이사항
};
void save(struct Stu stu[], FILE* fp) {  //void save(구조체 배열, 파일포인터)
    fp = fopen("test.txt", "w"); //쓰기전용으로 파일을 열어준다
    int a;

    if (fp == NULL) { //파일이 제대로 열렸는지 검사
        printf("실패 \n"); //파일포인터가 파일을 못열면 NULL값을 가진다
        return;
    }
    else if (fp != NULL) {
        for (a = 0; a < MAX_STD; a++) {  //저장을 위해 for문 사용

            fprintf(fp, "%s", (stu + a)->name); //fprintf는 파일에 데이터를 넣기위해 사용
            fprintf(fp, "%s", (stu + a)->ad);
            fprintf(fp, "%s", (stu + a)->ph);
            fprintf(fp, "%s", (stu + a)->fu);
            fprintf(fp, "%s", (stu + a)->sp);

        }

    }
    fclose(fp); //파일입출력을 완료하면 꼭닫아주자

}

void addStu(struct Stu stu[]) {
    int a;

    //입력

    for (a = 0; a < MAX_STD; a++) {
        printf("※ 추가할 데이터를  입력하세요.\n");
        printf("+==========================+\n");
        printf("이름 : ");
        fputc(0, stdin); //스트림이 stdin
        fgets((stu + a)->name, sizeof((stu + a)->name), stdin);
        printf("주소 : ");
        fputc(0, stdin);
        getchar(); //입력버퍼 비우기
        fgets((stu + a)->ad, sizeof((stu + a)->ad), stdin);
        printf("연락처 : ");
        fputc(0, stdin);
        fgets((stu + a)->ph, sizeof((stu + a)->ph), stdin);
        printf("진로사항 : ");
        fputc(0, stdin);
        fgets((stu + a)->fu, sizeof((stu + a)->fu), stdin);
        printf("특이사항 : ");
        fgets((stu + a)->sp, sizeof((stu + a)->sp), stdin);
    }

    //출력

    printf("+==========================+\n");
    printf("업데이트된 결과\n");
    for (a = 0; a < MAX_STD; a++) {
        printf("이름 : ");
        printf("%s", (stu + a)->name);
        printf("주소 : ");
        printf("%s", (stu + a)->ad);
        printf("연락처 : ");
        printf("%s", (stu + a)->ph);
        printf("진로사항 : ");
        printf("%s", (stu + a)->fu);
        printf("특이사항 : ");
        printf("%s", (stu + a)->sp);

    }

}
void modifyStu(struct Stu stu[]) {

    char num[10];
    int a;

    printf("검색할 학생의 이름 : ");
    fputc(0, stdin);
    fgets(num, sizeof(num), stdin);
    for (a = 0; a < MAX_STD; a++) {
        if (strcmp(num, (stu + a)->name) == 0) {
            printf("※ 추가할 데이터를  입력하세요.\n");
            printf("+==========================+\n");
            printf("이름 : ");
            fputc(0, stdin);
            fgets((stu + a)->name, sizeof((stu + a)->name), stdin);
            printf("주소 : ");
            fputc(0, stdin);
            getchar();
            fgets((stu + a)->ad, sizeof((stu + a)->ad), stdin);
            printf("연락처 : ");
            fputc(0, stdin);
            fgets((stu + a)->ph, sizeof((stu + a)->ph), stdin);
            printf("진로사항 : ");
            fputc(0, stdin);
            fgets((stu + a)->fu, sizeof((stu + a)->fu), stdin);
            printf("특이사항 : ");
            fgets((stu + a)->sp, sizeof((stu + a)->sp), stdin);

        }
    }
}
void searchStu(struct Stu stu[]) {

    char num[10] = { 0, };
    int a;

    printf("검색할 학생의 이름 : ");
    fputc(0, stdin);
    fgets(num, sizeof(num), stdin);
    for (a = 0; a < MAX_STD; a++) {

        if (strcmp(num, (stu + a)->name) == 0) {
            printf("이름 : ");
            printf("%s", (stu + a)->name);
            printf("주소 : ");
            printf("%s", (stu + a)->ad);
            printf("연락처 : ");
            printf("%s", (stu + a)->ph);
            printf("진로사항 : ");
            printf("%s", (stu + a)->fu);
            printf("특이사항 : ");
            printf("%s", (stu + a)->sp);

        }
    }

}
void load(struct Stu stu[], FILE* fp) {
    fp = fopen("test.txt", "r");
    int a = 0;

    if (fp == NULL) {
        printf("실패 \n");
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
            if (feof(fp))break;    //파일의 제일 마지막에 도달하면 탈출
        }

    }
    fclose(fp);

}


int main()
{
    int i = 0;
    struct Stu stu[25];
    FILE* fp = NULL;  //파일포인터 선언

    load(stu, fp);

    while (1) {
        printf("+= ======================== = +\n");
        printf("1.추가\n");
        printf("2.수정\n");
        printf("3.검색\n");
        printf("4.종료\n");
        printf("+= ======================== = +\n");
        printf("정수값을 입력하시오\n");
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


//1. 컴퓨터공학과 4학년 동료들을 간단한  정보를 입력하거나 업데이터 할수 있는 간단한 프로그램이다.
//2. 입력하거나 업데이터한 데이터는 파일로 저장한다.
//(간단한 데이터 베이스라고 하겠다)
//3. 또 저장된 데이터는 검색할 수 있다.
//4. 연락처 데이터는 구조체로 사용해서 파일을 구성한다.
//5. 화면으로 데이터 입력을 위한 메뉴와 업데이터된 메뉴는 아래와 같다.
//6. 입력 데이터는 10개 이상
//7. 실행 결과
//(1) 데이터 입력을 위한 메뉴
//+= ======================== = +
//1. 추가 :
//2. 수정 :
  //  3. 검색 :
    //4. 종료
   // += ======================== = +

    //정수값을 입력하세요 : 1
//이름, 주소, 연락처, 진로사항, 특이사항