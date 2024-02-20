#include <stdio.h>
#include <stdlib.h>
float ComputeSum(int n, float x)
{
    if(n == 0)
    {
        printf("0");
        return 0;
    }
    printf("(%d/%0.2f) + ",n, x);
    return n/x + ComputeSum(n-1, x);
}
int main()
{
int n;
float x;
scanf("%d%f",&n,&x);
    printf("F(%d,%0.2f) = ",n,x);
    printf(" = %0.2f", ComputeSum(n,x));
    return 0;
}
