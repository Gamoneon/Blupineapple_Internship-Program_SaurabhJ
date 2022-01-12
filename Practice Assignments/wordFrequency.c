#include<stdio.h>
#include <string.h>
typedef struct wordFrequency
{
    char word[20];
    int count;

}wordFrequency;

int main()
{
    char para[500], sym[]=" @.,;:!?'\\\"";
    wordFrequency * word= (wordFrequency*)malloc(sizeof(wordFrequency));

    printf("Enter your paragraph:");
    scanf("%[^\n]%*c", para);

    printf("Enter your word to find number of frequencies:");
    scanf("%s",word->word);
    word->count=0;

    char * token= strtok(para,sym);

    while(token!=NULL) 
        {
            if(strcmp(token,word->word)==0) word->count++;
            token = strtok(NULL,sym);
        }

    printf("\nFrequency of %s in given paragraph is %d.",word->word,word->count);
    return 0;    
}