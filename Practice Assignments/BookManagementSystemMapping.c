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
NODE *temp, *newNode;

void init()
{
    // Init all values to -1 & next pointers to NULL
    for (int i = 0; i < SIZE; i++)
    {
        hash[i].key = -1;
        hash[i].next = NULL;
    }
}

void insert()
{
    int id;
    printf("\nEnter Book ID: ");
    scanf("%d", &id);

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

void display(int id)
{
    if (printAll)
    {
        printf("\nEntered values are:");
        for (int i = 0; i < SIZE; i++)
        {
            if (hash[i].key != -1)
                printf("\n%d\t%s", hash[i].key, hash[i].name);
            temp = hash[i % SIZE].next;
            while (temp != NULL)
            {
                if (hash[i].key != -1)
                    printf("\n%d\t%s", temp->key, temp->name);
                temp = temp->next;
            }
        }
    }
    else
    {
        if (hash[id % SIZE].key == id)
            printf("\n%d\t%s", hash[id].key, hash[id].name);
        else
        {
            temp = hash[id % SIZE].next;
            while (temp != NULL && temp->key != id)
            {
                temp = temp->next;
            }
            printf("\n%d\t%s", temp->key, temp->name);
        }
    }
    printAll = 1;
}

void delete (int id)
{
    if (hash[id % SIZE].key == id)
    {
        hash[id % SIZE].key = -1;
        strcpy(hash[id % SIZE].name, "");
        printf("Entry Deleted successfully!");
    }
    else
    {
        temp = hash[id % SIZE].next;
        while (temp != NULL && temp->key != id)
        {
            newNode = temp;
            temp = temp->next;
        }
        
        newNode->next = temp->next;
        printf("Entry Deleted successfully!");
        free(temp);
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
            display(id);
            break;
        case 3:
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
