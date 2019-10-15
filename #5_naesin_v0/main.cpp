#include <stdio.h>

using namespace std;

int main()
{
    int p,s,j,t;
    printf("학생 수 입력\n");
    scanf("%d", &p);
    printf("등수 입력\n");
    scanf("%d", &s);
    t=s;
    printf("%d\n", s);
    float res=0;
    int i[9];
    i[0]=0;
    i[1]=(float)p/100*4;
    i[2]=(float)p/100*11;
    i[3]=(float)p/100*23;
    i[4]=(float)p/100*40;
    i[5]=(float)p/100*60;
    i[6]=(float)p/100*77;
    i[7]=(float)p/100*89;
    i[8]=(float)p/100*96;
    i[9]=(float)p;
    s=t;
    for(j=1; j<=9; j++)
        printf("i[%d]=%d\n", j, i[j]);
    for(j=1; j<=9; j++)
    {
        printf("s=%d, i[%d]=%d\n",s, j,i[j]);

        if(s<i[j])
        {
            if(j>1)
                s=s-i[j-1];

            printf("%d\n",s);
            res = j + (float)s/(i[j]-i[j-1]);
            printf("%g\n", res);
            break;
        }
    }
    return res;;
}
