//Find total number of occurrences of each digits(0-9)
#include <stdio.h>
int main()
{
    int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, num, i;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("The occurrences of digits in %d are:\n", num);

    while (num % 10)
    {
        count[(num % 10)]++;
        num = num / 10;
    }

    for (i = 0; i < 10; i++)
        (count[i] != 0) ? printf("%d: %d\n", i, count[i]) : printf("");
    return 0;
}