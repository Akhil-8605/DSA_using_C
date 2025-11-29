#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *last = NULL;

void insertFront(int x)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = x;

    if (last == NULL)
    {
        last = newNode;
        last->next = last;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
    }
}

void insertEnd(int x)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = x;

    if (last == NULL)
    {
        last = newNode;
        last->next = last;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void deleteFront()
{
    if (last == NULL)
    {
        printf("List Empty!\n");
        return;
    }

    struct Node *t = last->next;

    if (last == t)
        last = NULL;
    else
        last->next = t->next;

    free(t);
}

void display()
{
    if (last == NULL)
    {
        printf("List Empty!\n");
        return;
    }

    struct Node *t = last->next;
    printf("Circular List: ");
    do
    {
        printf("%d ", t->data);
        t = t->next;
    } while (t != last->next);
    printf("\n");
}

int main()
{
    int ch, x;
    do
    {
        printf("\n1.Insert Front 2.Insert End 3.Delete Front 4.Display 5.Exit\nChoice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Value: ");
            scanf("%d", &x);
            insertFront(x);
            break;
        case 2:
            printf("Value: ");
            scanf("%d", &x);
            insertEnd(x);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            display();
            break;
        }
    } while (ch != 5);
}
