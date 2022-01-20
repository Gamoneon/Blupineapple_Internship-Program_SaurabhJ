#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char words[][10] = {"south", "sound", "ajay", "arab", "ratio", "range", "rover", "worthy", "warner", "phantom", "poverty", "quack", "quads",
                    "cab", "cat", "axon", "amen", "album", "alarm", "white", "whole", "while", "if", "is", "inch", "itch", "fork", "folk"};
int wordcnt = 0, flag = 0;
typedef struct treenode
{
    char word[50];
    struct treenode *left, *right;
} tree;

tree *insert(tree *root, char *word)
{
    if (root == NULL)
    {
        root = (tree *)malloc(sizeof(tree));
        strcpy(root->word, word);
        root->left = NULL;
        root->right = NULL;
        if (flag)
            printf("Word added successfully!\n");
    }
    else
    {
        int cmp = strcmp(root->word, word);

        if (cmp != 0)
        {
            if (cmp > 0)
                root->left = insert(root->left, word);
            else
                root->right = insert(root->right, word);
        }
        else
            printf("Word present already!\n");
    }
    return root;
}

tree *findRoot(tree *root, char *word)
{
    if (root)
    {
        int cmp = (root->word[0] - tolower(word[0]));
        if (cmp == 0)
            return root;
        else if (cmp > 0)
            return findRoot(root->left, word);
        else
            return findRoot(root->right, word);
    }
}

void displaytree(tree *root)
{
    if (root)
    {
        displaytree(root->left);
        printf("%s\t", root->word);
        displaytree(root->right);
    }
}

void compare_words(char *treeWord, char *word)
{
    int i = 0;
    while (treeWord[i] != '\0')
    {
        if (word[i] == '-' || treeWord[i] == tolower(word[i]))
        {
            i++;
            continue;
        }
        else
            break;
    }
    if (i == strlen(word))
    {
        printf("%d.%s \n", (wordcnt++) + 1, treeWord);
    }
}
void findWords(tree *root, char *word)
{
    if (root)
    {
        findWords(root->left, word);
        if (strlen(root->word) == strlen(word))
            (compare_words(root->word, word));

        findWords(root->right, word);
    }
}

int main()
{
    int i = 0, ch;
    tree *root = NULL, *temp = (tree *)malloc(sizeof(tree));

    printf("Loading dictionary...\n\n");

    for (i = 0; i < sizeof(words) / sizeof(words[0]); i++)
        root = insert(root, words[i]);
    flag = 1;

    printf("Words available are:\n");
    displaytree(root);

    char word[50];

    while (1)
    {
        printf("\nChoose an option:\n1.Search\t2.Insert\t3.Print All\t4.Quit\n# ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter word to search with unknown characters as dash (E.g. 'c--' length(3) with 2 dash or '-l--m' ):\n-> ");
            fflush(stdin);
            scanf("%[^\n]%*c", word);
            wordcnt = 0;
            temp =(word[0]!='-')?findRoot(root, word):root;
            findWords(temp, word);
            if (wordcnt == 0)
                printf("Word not found!\n");
            break;
        case 2:
            printf("Enter new word to add in Dictionary:\n->");
            fflush(stdin);
            scanf("%[^\n]%*c", word);
            root = insert(root, word);
            break;
        case 3:
            displaytree(root);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Wrong choice!\nTry again.");
            break;
        }
    }
    return 0;
}