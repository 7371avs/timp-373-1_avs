#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    double pr=1;
    int x;
    for(int i=0;i<n;i++)
    {
        scanf ("%d",&x);
        pr*=(x-i);
    }
    printf("%lf\n", pr);
}
