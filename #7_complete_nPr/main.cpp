#include <stdio.h>
#include <conio.h>
int main()
{
    long long int s;
    printf("Input Number : ");
    scanf("%lld", &s);
    long long int f[s+1]={0};
    f[1]=0;
    f[2]=1;
    for(long long int i=3; i<=s; i++)
    {
        f[i]=(i-1)*(f[i-1]+f[i-2]);
    }
    printf("f[%lld]=%lld\nPress any key to continue. . . ", s, f[s]);
    getch();


    return 0;
}
