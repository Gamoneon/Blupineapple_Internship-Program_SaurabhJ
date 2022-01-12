#include<stdio.h>
#include <string.h>
int IsPali(char *);
void main()
{
    char str[30];
    printf("Enter a string: ");
    scanf("%s",&str);
    (IsPali(str))?printf("'%s' is a palindrome!",str):printf("'%s' is NOT a palindrome!",str);
}

int IsPali(char* str)
{
    int i=0,j,cnt=0;
    j=strlen(str)-1;
    while(str[i++]==str[j--] && i<=j);
    return (i>j);
}