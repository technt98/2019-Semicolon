#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int ret=1;
int scan()
{
    int c, n, neg=1;
    while(c=getchar()!='\n')
    {
        if(c==27)
        {
            ret=0;
        break;
        }
        if(c=='-') neg=-1;
        if(c>='0' && c<='9')
            n=n*10+c-48;
    }
    return n*neg;
}
int main()
{
    int ch, r, t, n1, n2, tr=0, c=0, res;
    srand((unsigned) time(NULL));
    printf("Press any key to start..\n");
    while(ret)
    {
        printf("Q%d. ", ++c);
        r=rand();
        t=r*5425;
        n1=r*2506%127+1;
        n2=r*6329%127+1;
        if(!(t%6)) // ~
        {
            printf("~ %d = ", n1);
            res=scan();
            if(~n1 == res)
            {
                printf("[True]\n");
                tr++;
            }
            else
                printf("[False]\n");
        }
        else if(t%6==1) // &
        {
            printf("%d & %d = ", n1, n2);
            res=scan();
            if(n1&n2 == res)
            {
                printf("[True]\n");
                tr++;
            }
            else
                printf("[False]\n");

        }
        else if(t%6==2) // ^
        {
            printf("%d ^ %d = ", n1, n2);
            if(n1^n2 == scan())
            {
                printf("[True]\n");
                tr++;
            }
            else
                printf("[False]\n");

        }
        else if(t%6==3) // |
        {
            printf("%d | %d = ", n1, n2);
            res=scan();
            if(n1|n2 == res)
            {
                printf("[True]\n");
                tr++;
            }
            else
                printf("[False]\n");

        }
        else if(t%6==4) // <<
        {
            printf("%d << %d = ", n1, n2);
            res=scan();
            if(n1<<n2 == res)
            {
                printf("[True]\n");
                tr++;
            }
            else
                printf("[False]\n");

        }
        else // >>
        {
            printf("%d >> %d = ", n1, n2);
            res=scan;
            if(n1>>n2 == res)
            {
                printf("[True]\n");
                tr++;
            }
            else
                printf("[False]\n");

        }

    }
    return 0;
}
