#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    time_t timer;
    struct tm *t;
    timer = time(NULL);
    t = localtime (&timer);
    int sc=0, mn=0, hr=0, d, mt, yr, ext=0, temp=0, temp1, temp2=0, temp4;
    long long int r=0;
    int tsc=t->tm_sec, tmn=t->tm_min, thr=t->tm_hour, td=t->tm_mday, tmt=t->tm_mon+1, tyr=t->tm_year+1900, tmt_, tsc_;
    tmt_ = tmt;
    tsc_ = tsc;
    printf("Local time : %02d/%02d/%04d %02d:%02d:%02d\n", td, tmt, tyr, thr, tmn, tsc);
    tsc+=tmn*60+thr*3600+td*86400;
    printf("tsc = %d\n", tsc);
    temp=td;
    while(tmt>1)
    {
        tmt--;
        if(tmt==2 && (tyr%4==0 && (tyr%100!=0 || tyr%400==0)))
            temp++;
        else if(tmt==2);
        else if(tmt==4 || tmt==6 || tmt==9 || tmt==11)
            temp+=2;
        else temp+=3;
        temp+=28;
        printf("tmt = %d, +%d\n", tmt, temp);
    }
    tmt = tmt_;
    tsc+=temp*86400;
    temp4=tsc;
    tsc=tsc_;
    tsc_=temp4;
    printf("tsc = %d\n", tsc);



    while(1)
    {
        printf("출생년도 입력\n");
        scanf("%d", &yr);

        if(yr>tyr)
        {
            printf("정확한 ");
            continue;
        }
        else
        {
            if(yr==tyr)
                temp2=1;
            break;
        }


    }
    if(yr%4==0 && (yr%100!=0 || yr%400==0))
        ext++;
    while(1)
    {
        printf("출생월 입력\n");
        scanf("%d", &mt);
        if(mt>12 || mt<1)
        {
            printf("정확한 ");
            continue;
        }
        if(temp2 && mt>tmt)
        {
            printf("정확한 ");
            continue;
        }
        else
        {
            if(mt<tmt)
                temp2=0;
            break;
        }
    }
    if(mt==2)
        temp1=0;
    else if(mt==4 || mt==6 || mt==9 || mt==11)
        temp1=2;
    else temp1=1;
    while(1)
    {
        printf("출생일 입력\n");
        scanf("%d", &d);
        if(d<1)
        {
            printf("정확한 ");
            continue;
        }
        if(temp1+d>32)
        {
            printf("정확한 ");
            continue;
        }
        else if(temp1==0)
        {
            if(ext && d>29)
            {
                printf("정확한 ");
                continue;
            }
            else if(!ext && d>28)
            {
                printf("정확한 ");
                continue;
            }
        }
        if(temp2 && d>td)
        {
            printf("정확한 ");
            continue;
        }
        else
        {
            if(d<td)
                temp2=0;
            break;
        }
    }
    char temp3=0;
        scanf("%c", &temp3);
    while(1)
    {
        printf("출생시각을 알고 계십니까: Y/N\n");
        scanf("%c", &temp3);
        if(temp3=='y' || temp3=='Y')
        {
            temp=1;
            break;
        }
        else if(temp3=='n' || temp3=='N')
        {
            temp=0;
            break;
        }
        else scanf("%c", &temp3);

    }
    if(temp)
    {
        while(1)
        {
            printf("출생시 입력 : 24시간 단위 00 - 23\n");
            scanf("%d", &hr);
            if(hr>23 || hr<0)
            {
                printf("정확한 ");
                continue;
            }
            if(temp2 && hr>thr)
                printf("정확한 ");
            else
            {
                if(hr<thr)
                    temp2=0;
                break;
            }
        }
        while(1)
        {
            printf("출생분 입력 00 - 59\n");
            scanf("%d", &mn);
            if(mn>59 || mn<1)
            {
                printf("정확한 ");
                continue;
            }
            if(temp2 && mn>tmn)
                printf("정확한 ");
            else
            {
                if(mn<tmn)
                    temp2=0;
                break;
            }
        }
        while(1)
        {
            printf("출생초 입력 00 - 59\n");
            scanf("%d", &sc);
            if(sc>59 || sc<0)
            {
                printf("정확한 ");
                continue;
            }
            if(temp2 && sc>tsc)
                printf("정확한 ");
            else
            {
                if(sc<tsc)
                    temp2=0;
                break;
            }
        }
    }
    printf("출생시각 : %02d/%02d/%04d %02d:%02d:%02d\n", d, mt, yr, hr, mn, sc);
    if(!(yr==tyr && mt==tmt)) // 현재 월에 태어나지 않음
    {
        r+=tsc+tmn*60+thr*3600+td*86400; // 현재 월까지 경과 초 계산
        tsc=0;
        tmn=0;
        thr=0;
        if(tyr%4==0 && (tyr%100!=0 || tyr%400==0))
            ext=1;
        else
            ext=0;
        if(tmt==2 && ext)
            td=29;
        else if (tmt==2)
            td=28;
        else if (tmt==4 || tmt==6 || tmt==9 || tmt==11)
            td=30;
        else
        {
            td=31;
            hr=24;
        }
        tmt--;
    }
    while(1)
    {
        if(yr==tyr && mt==tmt)
        {
            r+=(tsc-sc)+(tmn-mn)*60+(thr-hr)*3600+(td-d)*86400;
            break;
        }
        if(!tmt)
        {
            tyr--;
            tmt=12;
            continue;
        }
        if(tyr%4==0 && (tyr%100!=0 || tyr%400==0))
        {
            ext=1;
        }
        else
            ext=0;
        if(tmt==2 && ext)
            td=29;
        else if (mt==2)
            td=28;
        else if (tmt==4 || tmt==6 || tmt==9 || tmt==11)
            td=30;
        else
            td=31;
        r+=td*86400;
        tmt--;

    }
    printf("경과 초 : %lld s", r);
    getch();
    return 0;
}
