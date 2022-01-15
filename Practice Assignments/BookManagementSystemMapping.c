#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 50
int printAll = 1;
typedef struct node NODE;

struct node
{
    int key;
    char name[20];
    NODE *next;
};

NODE hash[SIZE];
NODE *temp, *newNode, *prev;

void init()
{
    // Init all values to -1 & next pointers to NULL
    for (int i = 0; i < SIZE; i++)
    {
        hash[i].key = -1;
        hash[i].next = NULL;
    }
}

int display(int id)
{
    if (printAll)
    {
        printf("\nBook records are:\nBOOK_ID:\t\tBOOK_NAME");
        for (int i = 0; i < SIZE; i++)
        {
            temp = &hash[i % SIZE];
            while (temp != NULL)
            {
                if (hash[i].key != -1)
                    printf("\n%d:\t\t\t%s", temp->key, temp->name);
                temp = temp->next;
            }
        }
        printf("\n");
    }
    else
    {
        printAll = 1;
        if (hash[id % SIZE].key == id)
        {
            return (printf("\nRecord found:\n%d:\t\t%s\n", hash[id].key, hash[id].name));
        }
        else
        {
            temp = hash[id % SIZE].next;
            while (temp != NULL && temp->key != id)
            {
                temp = temp->next;
            }
            if (temp != NULL)
                return (printf("\nRecord found:\n%d:\t\t%s\n", temp->key, temp->name));
            else
                return 0;
        }
    }
}

void delete (int id)
{
    printAll = 0;
    if (display(id))
    {
        printAll = 1;
        temp = &hash[id % SIZE];
        if (temp->key == id)
            hash[id % SIZE] = *(temp->next);

        else
        {
            prev = NULL;
            while (temp != NULL)
            {
                if (temp->key == id)
                    break;
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
        }
        printf("\nEntry Deleted successfully!\n");
        free(temp);
    }
    else
    {
        printAll = 1;
        printf("\nRecord not found.\n");
    }
}

void insert()
{
    int id;
    printAll = 0;
    printf("\nEnter Book ID: ");
    scanf("%d", &id);
    if (!display(id))
    {
        printAll = 1;
        if (hash[id % SIZE].key == -1)
        {
            hash[id % SIZE].key = id;
            printf("Enter Book Name: ");
            scanf("%s", hash[id % SIZE].name);
        }
        else
        {
            newNode = (NODE *)malloc(sizeof(NODE));
            newNode->key = id;
            printf("Enter Book Name: ");
            scanf("%s", newNode->name);

            temp = &(hash[id % SIZE]);
            printf("\nNew Node added.\n");

            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = NULL;
        }
    }
    else
    {
        printAll = 1;
        printf("\nID exists already.\n");
    }
}

int main()
{
    init();
    int id, choice;
    while (1)
    {
        printf("\n1. Insert\n2. Search\n3. Print All\n4. Delete\n5. Quit\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            printAll = 0;
            printf("Enter Book ID:");
            scanf("%d", &id);
            if (!display(id))
                printf("\nRecord not found.\n");
            break;
        case 3:
            printf("Status: %d", printAll);
            display(0);
            break;
        case 4:
            printf("Enter Book ID:");
            scanf("%d", &id);
            delete (id);
            break;
        case 5:
            exit(0);
        default:
            printf("\nWrong Choice!\nTry again or Enter \"5\" to quit.\n");
            break;
        }
    }

    return 0;
}
