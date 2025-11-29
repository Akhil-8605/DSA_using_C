#include <stdio.h>

#define SIZE 5
int cq[SIZE];
int front = -1, rear = -1;

int isFull()
{
    return (front == (rear + 1) % SIZE);
}

int isEmpty()
{
    return (front == -1);
}

void enqueue(int x)
{
    if (isFull())
    {
        printf("Circular Queue Full!\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % SIZE;
    cq[rear] = x;
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Circular Queue Empty!\n");
        return;
    }
    printf("Dequeued: %d\n", cq[front]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue Empty!\n");
        return;
    }

    printf("Circular Queue: ");
    int i = front;
    while (1)
    {
        printf("%d ", cq[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main()
{
    int ch, x;

    do
    {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value: ");
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
