#include <stdio.h>

#define SIZE 50
int queue[SIZE];
int front = 0, rear = -1;

void enqueue(int x)
{
    if (rear == SIZE - 1)
        printf("Queue Overflow!\n");
    else
        queue[++rear] = x;
}

void dequeue()
{
    if (front > rear)
        printf("Queue Underflow!\n");
    else
        printf("Dequeued: %d\n", queue[front++]);
}

void display()
{
    if (front > rear)
        printf("Queue Empty!\n");
    else
    {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
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
