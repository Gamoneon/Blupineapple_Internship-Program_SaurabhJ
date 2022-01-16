#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
        printf("%s = %s",word,root->word);
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else
    {
        int cmp = strcmp(root->word, word);
        printf("%d\n",cmp);
        if (cmp != 0)
            (cmp > 0) ? insert(root->left, word) : insert(root->right, word);
        return root;
    }
}

void displaytree(tree *root)
{
    if (root)
    {
        displaytree(root->left);
        printf(" %s ", root->word);
        displaytree(root->right);
    }
}

int main()
{
    int ch;
    char word[50];
    tree *root = NULL;
    while (1)
    {
        printf("\n1.Insert\t2.Display\t3.Quit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter word:");
            scanf("%s", word);
            root=insert(root, word);
            break;
        case 2:
            displaytree(root);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Wrong choice!\nTry again.");
            break;
        }
    }
    return 0;
}