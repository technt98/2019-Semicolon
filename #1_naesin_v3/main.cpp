#include <stdio.h>
#include <conio.h>
int main()
{
    int s, i, s1=0, s2=0;
    printf("����� �Է� : ");
    scanf("%d", &s);
    int grade, n;
    float result;
    for(i=1; i<=s; i++)
    {
        printf("======================\n");
        printf("%d�� ���� ������� �Է� : ", i);
        scanf("%d", &grade);
        printf("%d�� ���� ������ �Է� : ", i);
        scanf("%d", &n);
        s1+=grade*n;
        s2+=n;
    }
    printf("======================\n");
    result = (float)s1/s2;
    printf("������ ��� ��� ��� : %.6f", result);
    getch();

    return 0;
}
