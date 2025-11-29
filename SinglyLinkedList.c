#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertFront(int x)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int x)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node *t = head;
    while (t->next != NULL)
        t = t->next;
    t->next = newNode;
}

void deleteFront()
{
    if (head == NULL)
    {
        printf("List empty!\n");
        return;
    }
    struct Node *t = head;
    head = head->next;
    free(t);
}

void deleteEnd()
{
    if (head == NULL)
    {
        printf("List empty!\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    struct Node *t = head;
    while (t->next->next != NULL)
        t = t->next;
    free(t->next);
    t->next = NULL;
}

void display()
{
    struct Node *t = head;
    printf("List: ");
    while (t != NULL)
    {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int main()
{
    int ch, x;
    do
    {
        printf("\n1.Insert Front 2.Insert End 3.Delete Front 4.Delete End 5.Display 6.Exit\nChoice: ");
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
            deleteEnd();
            break;
        case 5:
            display();
            break;
        }
    } while (ch != 6);
}
