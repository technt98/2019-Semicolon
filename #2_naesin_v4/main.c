#include <stdio.h>

int main()
{
    int n[6];
    printf("국어 등급 입력 : ");
    scanf("%d", &n[0]);
    printf("수학 / 수학 I 등급 입력 : ");
    scanf("%d", &n[1]);
    printf("영어 등급 입력 : ");
    scanf("%d", &n[2]);
    printf("사회 등급 입력 : ");
    scanf("%d", &n[3]);
    printf("과학 등급 입력 : ");
    scanf("%d", &n[4]);
    printf("한문 I / 정보과학 등급 입력 : ");
    scanf("%d", &n[5]);
    printf("==================\n");
    printf("평균 등급 : %.3f\n", (n[0]*3+n[1]*6+n[2]*3+n[3]*3+n[4]*4+n[5]*3)/22.0);
    getch();
    return 0;
}
