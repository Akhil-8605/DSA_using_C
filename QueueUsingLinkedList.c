#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue Empty!\n");
        return;
    }

    printf("Dequeued: %d\n", front->data);
    struct Node *t = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(t);
}

void display()
{
    struct Node *t = front;
    printf("Queue: ");
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main()
{
    int ch, x;
    do
    {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Value: ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        }
    } while (ch != 4);
}
