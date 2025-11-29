#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

struct Node *createNode(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertFront(int x)
{
    struct Node *newNode = createNode(x);
    if (head != NULL)
    {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
}

void deleteFront()
{
    if (head == NULL)
    {
        printf("List empty!\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    if (head)
        head->prev = NULL;
    free(temp);
}

void display()
{
    struct Node *t = head;
    printf("List: ");
    while (t != NULL)
    {
        printf("%d <-> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int main()
{
    int ch, x;

    do
    {
        printf("\n1.Insert Front  2.Delete Front  3.Display  4.Exit\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &x);
            insertFront(x);
            break;
        case 2:
            deleteFront();
            break;
        case 3:
            display();
            break;
        }
    } while (ch != 4);
}
