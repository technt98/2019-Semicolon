#include <stdio.h>
#include <conio.h>
#include <windows.h>

int grd[9]= {0}; // ��� �� ���� ���
int i, n, a; // i: �ݺ��� ����, n: ���� �κ� ���� ���, a: ��� �� ���� ���
float crd, p; // crd: ���� ���, p: ��� �� ���� 1���� ��ġ

void re(void)
{
    printf("��Ȯ�� ���� �Է��Ͻʽÿ�..\n\n");
}
void pr(void) // ���м� ��� �Լ�
{
    printf("======================\n");
}

void calc(int g) // ���� ��� ����ϴ� �Լ�
{
    for(i=1; i<=9; i++) // ���� 9��� ����
    {
        if(grd[i-1]<g && g<=grd[i]) // ����� i-1��� �� ��, i��� �� �Ʒ�
        {
            n=i; // ���� ����� i���
            a=g-grd[i-1]; // ��� �� ���� ���
        }
    }
    p=(float)(a-1)/(grd[n]-grd[n-1]); // a-1: ���� ��� �� 1���̸� n.000���
    crd=n+p; // ���� ��� (���� �κ� ���� ��� + �Ҽ� �κ� ���� ���) ���� ���� - �ֹ߼�.
}

//============================================================================================
//============================================================================================
//============================================================================================

int main()
{
    int cls_N, sdnt_N, unit=0, u, j; // cls_N: �� ���� ��, sdnt_N: �� ������ ��, unit: ������ �� ��, u: ���� ������ ������, j: �ݺ��� ����
    float in=0, in_u=0, rn=0, rn_u=0, temp, sum=0; // i: ����, r: �Ǽ�. _u: ������ ���, n: ���ŵ�� (naesin), temp: �ӽú���, sum: ������ ��� ��� ���,

   HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   GetConsoleScreenBufferInfo(hC,&csbi);
   COLORREF a;

    pt1:
    printf("���� �� ������ �� �Է� : ");
    scanf("%d", &sdnt_N);
    if(sdnt_N<=0)
    {
        re();
        goto pt1;
    }
    pt2:
    printf("���� ��� �� ��� �� ���� �� �Է� : ");
    scanf("%d", &cls_N);
    if(cls_N<=0)
    {
        re();
        goto pt2;
    }

    pr();
    grd[0]=0; // 0��� ��
    grd[1]=sdnt_N*0.04; //1��� �� : 4%
    grd[2]=sdnt_N*0.11; // 2 : 11%
    grd[3]=sdnt_N*0.23; // 3 : 23%
    grd[4]=sdnt_N*0.4;  // 4 : 40%
    grd[5]=sdnt_N*0.6;  // 5 : 60%
    grd[6]=sdnt_N*0.77; // 6 : 77%
    grd[7]=sdnt_N*0.89; // 7 : 89%
    grd[8]=sdnt_N*0.96; // 8 : 96%
    grd[9]=sdnt_N;      // 9 : 100% = 1

    for(i=0; i<9; i++) // ���� ��� ���� ��� �ݺ���
    {
        if(grd[i]>=grd[i+1]) // i���� i+1�ƺ��� ���ų� ���� ��� - �� �Ҹ�
            printf("%d��� ���� : ����\n", i+1);
        else // �������� ���
            printf("%d��� ���� : %3d ~ %3d\n", i+1, grd[i]+1, grd[i+1]);
    }

    int rank[cls_N]; // �� ���� ��� ���� ���
    for(j=0; j<cls_N; j++) // �������ŭ �ݺ�
    {
        pr();
        pt3: //��Ȯ�� �� �Է����� �ʾ��� �� ��ȯ
        printf("%d�� ���� ���� �Է� : ", j+1); //j�� 0���� ���۵Ǳ� ����.
        scanf("%d", &rank[j]);
        if(rank[j]>sdnt_N || rank[j]<=0) // ����� �� �л� ������ ũ�ų�.. 0 ������ ���� �� : ��Ҹ� �Էµ� ���
        {
            re();
            goto pt3;
        }
        calc(rank[j]); // ����� ���� ��� ���
        //======================================================================================
        pt4: // ��Ȯ�� �� �Է����� �ʾ��� �� ��ȯ 2
        printf("%d�� ���� ������ �Է� : ", j+1); // j�� 0���� ���۵Ǳ� ���� 2
        scanf("%d", &u);
        if(u<1) // �������� �ּ� 1.
        {
            re();
            goto pt4;
        }
        //======================================================================================
        sum+=rank[j]*u; // ����� ������ ��
        rn_u+=crd*u; // ������ ��� �Ǽ� ���� ���
        in_u+=n*u; // ������ ��� ���� ���� ���
        rn+=crd; // ������ ���� �Ǽ� ���� ���
        in+=n; // ������ ���� ���� ���� ���
        unit+=u; // ������ ����
        printf("ȯ�� ���� ��� : %.15f\n", crd); // �� ���� ���� ��� ���
    }
    pr();
    printf("�������� ����� �Ǽ� ������ ��� ��� : %.15f\n", rn_u/unit);

    SetConsoleTextAttribute(hC,14); // ���� ���� : skyblue
    printf("�������� ����� ���� ������ ��� ��� : %g\n", in_u/unit);

    SetConsoleTextAttribute(hC,7); // ���� ����������
    printf("�������� ������� ���� �Ǽ� ������ ��� ��� : %.15f\n", rn/j);
    printf("�������� ������� ���� ���� ������ ��� ��� : %g\n", in/j);

    printf("�������� ����� ��� ��� : %g\n", sum/unit);
    pr();
    printf("Credit Calculator v1.12 :: Powered by Team Semi-Colon\nPress any key to continue.\n");
    getch(); // �ƹ� ��ư�̳� ������ �ٷ� ���α׷� ����
    return 0;
    /*
    v1.0 : ���� ���α׷� �ۼ� - ���Ƹ� ������Ʈ 20190717
    v1.1 : ���� ��Ȳ - ����� �Ҹ�Ǵ� ���, ���� ���� ���� �ԷµǴ� ��� 20190828
    v1.11 : �ڵ� ����, �ּ� �ۼ�
    v1.12 : ���� ���� 20190925
    v1.13 : ���� ��Ȳ - �Է� ���� �߸��� ��� 20190928
    */
}