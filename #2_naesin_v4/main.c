#include <stdio.h>

int main()
{
    int n[6];
    printf("���� ��� �Է� : ");
    scanf("%d", &n[0]);
    printf("���� / ���� I ��� �Է� : ");
    scanf("%d", &n[1]);
    printf("���� ��� �Է� : ");
    scanf("%d", &n[2]);
    printf("��ȸ ��� �Է� : ");
    scanf("%d", &n[3]);
    printf("���� ��� �Է� : ");
    scanf("%d", &n[4]);
    printf("�ѹ� I / �������� ��� �Է� : ");
    scanf("%d", &n[5]);
    printf("==================\n");
    printf("��� ��� : %.3f\n", (n[0]*3+n[1]*6+n[2]*3+n[3]*3+n[4]*4+n[5]*3)/22.0);
    getch();
    return 0;
}
