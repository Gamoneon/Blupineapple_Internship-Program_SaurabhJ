//Write a program to count the number of digits in a given integer
#include <stdio.h>
int main()
{
   int num, cnt = 0;
   printf("Enter the number to count number of digits: ");
   scanf("%d", &num);
   while (num % 10)
   {
      cnt++;
      num = num / 10;
   }
   printf("The number of digits are: %d", cnt);
   return 0;
}
