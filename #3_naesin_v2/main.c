#include <stdio.h>
#include <conio.h>
#include <windows.h>

int grd[9]= {0}; // 등급 컷 저장 어레이
int i, n, a; // i: 반복문 변수, n: 정수 부분 내신 등급, a: 등급 내 나의 등수
float crd, p; // crd: 내신 등급, p: 등급 내 나의 1분위 위치

void re(void)
{
    printf("정확한 값을 입력하십시오..\n\n");
}
void pr(void) // 구분선 출력 함수
{
    printf("======================\n");
}

void calc(int g) // 내신 등급 계산하는 함수
{
    for(i=1; i<=9; i++) // 내신 9등급 구분
    {
        if(grd[i-1]<g && g<=grd[i]) // 등수가 i-1등급 컷 위, i등급 컷 아래
        {
            n=i; // 너의 등급은 i등급
            a=g-grd[i-1]; // 등급 내 나의 등수
        }
    }
    p=(float)(a-1)/(grd[n]-grd[n-1]); // a-1: 내가 등급 내 1등이면 n.000등급
    crd=n+p; // 내신 등급 (정수 부분 내신 등급 + 소수 부분 내신 등급) 저장 변수 - 휘발성.
}

//============================================================================================
//============================================================================================
//============================================================================================

int main()
{
    int cls_N, sdnt_N, unit=0, u, j; // cls_N: 총 과목 수, sdnt_N: 총 수강자 수, unit: 단위수 총 합, u: 개별 과목의 단위수, j: 반복문 변수
    float in=0, in_u=0, rn=0, rn_u=0, temp, sum=0; // i: 정수, r: 실수. _u: 단위수 계산, n: 내신등급 (naesin), temp: 임시변수, sum: 단위수 계산 등수 평균,

   HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   GetConsoleScreenBufferInfo(hC,&csbi);
   COLORREF a;

    pt1:
    printf("현재 총 수강자 수 입력 : ");
    scanf("%d", &sdnt_N);
    if(sdnt_N<=0)
    {
        re();
        goto pt1;
    }
    pt2:
    printf("내신 등급 평가 대상 총 과목 수 입력 : ");
    scanf("%d", &cls_N);
    if(cls_N<=0)
    {
        re();
        goto pt2;
    }

    pr();
    grd[0]=0; // 0등급 컷
    grd[1]=sdnt_N*0.04; //1등급 컷 : 4%
    grd[2]=sdnt_N*0.11; // 2 : 11%
    grd[3]=sdnt_N*0.23; // 3 : 23%
    grd[4]=sdnt_N*0.4;  // 4 : 40%
    grd[5]=sdnt_N*0.6;  // 5 : 60%
    grd[6]=sdnt_N*0.77; // 6 : 77%
    grd[7]=sdnt_N*0.89; // 7 : 89%
    grd[8]=sdnt_N*0.96; // 8 : 96%
    grd[9]=sdnt_N;      // 9 : 100% = 1

    for(i=0; i<9; i++) // 내신 등급 범위 출력 반복문
    {
        if(grd[i]>=grd[i+1]) // i컷이 i+1컷보다 같거나 낮을 경우 - 컷 소멸
            printf("%d등급 범위 : 없음\n", i+1);
        else // 정상적인 경우
            printf("%d등급 범위 : %3d ~ %3d\n", i+1, grd[i]+1, grd[i+1]);
    }

    int rank[cls_N]; // 각 과목별 등수 저장 어레이
    for(j=0; j<cls_N; j++) // 과목수만큼 반복
    {
        pr();
        pt3: //정확한 값 입력하지 않았을 때 소환
        printf("%d번 과목 석차 입력 : ", j+1); //j는 0부터 시작되기 때문.
        scanf("%d", &rank[j]);
        if(rank[j]>sdnt_N || rank[j]<=0) // 등수가 총 학생 수보다 크거나.. 0 이하의 값일 때 : 헛소리 입력된 경우
        {
            re();
            goto pt3;
        }
        calc(rank[j]); // 등수의 내신 등급 계산
        //======================================================================================
        pt4: // 정확한 값 입력하지 않았을 때 소환 2
        printf("%d번 과목 단위수 입력 : ", j+1); // j는 0부터 시작되기 때문 2
        scanf("%d", &u);
        if(u<1) // 단위수는 최소 1.
        {
            re();
            goto pt4;
        }
        //======================================================================================
        sum+=rank[j]*u; // 등수에 단위수 곱
        rn_u+=crd*u; // 단위수 계산 실수 내신 등급
        in_u+=n*u; // 단위수 계산 정수 내신 등급
        rn+=crd; // 단위수 없는 실수 내신 등급
        in+=n; // 단위수 없는 정수 내신 등급
        unit+=u; // 단위수 누적
        printf("환산 내신 등급 : %.15f\n", crd); // 각 과목 내신 등급 출력
    }
    pr();
    printf("단위수를 계산한 실수 단위의 평균 등급 : %.15f\n", rn_u/unit);

    SetConsoleTextAttribute(hC,14); // 색상 변경 : skyblue
    printf("단위수를 계산한 정수 단위의 평균 등급 : %g\n", in_u/unit);

    SetConsoleTextAttribute(hC,7); // 색상 원래색으로
    printf("단위수를 계산하지 않은 실수 단위의 평균 등급 : %.15f\n", rn/j);
    printf("단위수를 계산하지 않은 정수 단위의 평균 등급 : %g\n", in/j);

    printf("단위수를 계산한 평균 등수 : %g\n", sum/unit);
    pr();
    printf("Credit Calculator v1.12 :: Powered by Team Semi-Colon\nPress any key to continue.\n");
    getch(); // 아무 버튼이나 누르면 바로 프로그램 종료
    return 0;
    /*
    v1.0 : 최초 프로그램 작성 - 동아리 프로젝트 20190717
    v1.1 : 예외 상황 - 등급이 소멸되는 경우, 범위 외의 값이 입력되는 경우 20190828
    v1.11 : 코드 정리, 주석 작성
    v1.12 : 색상 강조 20190925
    v1.13 : 예외 상황 - 입력 값이 잘못된 경우 20190928
    */
}
