//Find perfect numbers between 1 to n
/* A perfect number is a number whose value
 * is equal to addition of it's proper divisors
 * excluding the number itslef.
 */

#include<stdio.h>
int main()
{
    int sum,n,i,j;
    printf("Enter a number to find all Perfect numbers upto it: ");
    scanf("%d",&n);
    printf("All perfect numbers from 1 to %d are:\n",n);
    for(i=1;i<=n;i++)
    {
        sum=0;
        for(j=1;j<=i/2;j++) sum += (i%j==0)?j:0;
        (sum==i)?printf("%d\n",i):printf("");
    }
    return 0;
}