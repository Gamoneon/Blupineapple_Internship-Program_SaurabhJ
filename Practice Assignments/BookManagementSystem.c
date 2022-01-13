#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct book node;
int count;

struct book
{
    int id;
    char bookname[20];
    node *next;
};
node *head, *t, *prev;

node *createBook()
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->next = NULL;
    return newNode;
}

void insert()
{
    int id, flag = 0;
    char bname[20];

    if (head == NULL)
    {
        head = createBook();

        printf("Enter Book ID: ");
        scanf("%d", &(head)->id);

        printf("Enter Book Name: ");
        scanf("%s", head->bookname);

        count = 1;
        printf("Count set:%d", count);
    }
    else
    {
        node *temp = head;
        node *newNode = createBook();

        printf("Enter Book ID: ");
        scanf("%d", &id);

        for (node *t = head; t != NULL; t = t->next)
        {
            if (t->id == id)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            printf("Value already in use. Insert Another value!\n");
            insert();
        }
        else
        {
            newNode->id = id;
            printf("Enter Book Name: ");
            scanf("%s", newNode->bookname);

            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            count++;
            printf("Count set:%d", count);
        }
    }
}

int search(id)
{
    int flag = 0;
    for (t = head; t != NULL; t = t->next)
    {
        if (t->id == id)
        {
            flag = 1;
            printf("\nRecord found!\n%d : %s\n", t->id, t->bookname);
            break;
        }
    }
    if (flag != 1)
    {
        printf("\nRecord not found!\n");
        return 0;
    }
    return 1;
}

void PrintAll()
{
    
    printf("\nAvailbale Book records are-\nID:\tBook Name\n");
    for (t = head; t != NULL; t = t->next)
    {
        printf("%d :\t%s\n", t->id, t->bookname);
    }
}
int delete () 
{
    int id;
    printf("Enter ID:");
    scanf("%d", &id);
    if (search(id) == 1)
    {
        t=head;
        if(t->id==id)
        {
            head=t->next;
            free(t);
            return 1;
        }
        
        while (t!=NULL && t->id!=id)
        {
            prev=t;
            t=t->next;
        }

        prev->next = t->next;
        free(t);
        return 1;
    }   
}

int main()
{
    int i = 0, id, choice;
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
            printf("Enter ID:");
            scanf("%d", &id);
            if (head != NULL)
                search(id);
            else
                printf("\nList is empty.\n");
            break;
        case 3:
            PrintAll();
            break;
        case 4:
            if(delete()){
                printf("\nRecord deleted successfully!\n");
                PrintAll();
            }
            break;
        case 5:
            exit(0);
            break;
        }
    }
    return 0;
}
