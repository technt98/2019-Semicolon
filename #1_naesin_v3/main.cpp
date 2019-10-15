#include <stdio.h>
#include <conio.h>
int main()
{
    int s, i, s1=0, s2=0;
    printf("과목수 입력 : ");
    scanf("%d", &s);
    int grade, n;
    float result;
    for(i=1; i<=s; i++)
    {
        printf("======================\n");
        printf("%d번 과목 석차등급 입력 : ", i);
        scanf("%d", &grade);
        printf("%d번 과목 단위수 입력 : ", i);
        scanf("%d", &n);
        s1+=grade*n;
        s2+=n;
    }
    printf("======================\n");
    result = (float)s1/s2;
    printf("단위수 계산 등급 평균 : %.6f", result);
    getch();

    return 0;
}
