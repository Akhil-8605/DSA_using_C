#include <stdio.h>
#define SIZE 10

int deque[SIZE];
int front = -1, rear = -1;

int isFull()
{
    return (front == (rear + 1) % SIZE);
}

int isEmpty()
{
    return (front == -1);
}

void insertFront(int x)
{
    if (isFull())
    {
        printf("Deque Full!\n");
        return;
    }

    if (isEmpty())
        front = rear = 0;
    else
        front = (front - 1 + SIZE) % SIZE;

    deque[front] = x;
}

void insertRear(int x)
{
    if (isFull())
    {
        printf("Deque Full!\n");
        return;
    }

    if (isEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;

    deque[rear] = x;
}

void deleteFront()
{
    if (isEmpty())
    {
        printf("Deque Empty!\n");
        return;
    }

    printf("Deleted: %d\n", deque[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void deleteRear()
{
    if (isEmpty())
    {
        printf("Deque Empty!\n");
        return;
    }

    printf("Deleted: %d\n", deque[rear]);
    if (front == rear)
        front = rear = -1;
    else
        rear = (rear - 1 + SIZE) % SIZE;
}

void display()
{
    if (isEmpty())
    {
        printf("Deque Empty!\n");
        return;
    }

    printf("Deque: ");
    int i = front;
    while (1)
    {
        printf("%d ", deque[i]);
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
        printf("\n1.Insert Front 2.Insert Rear 3.Delete Front 4.Delete Rear\n");
        printf("5.Display 6.Exit\nEnter choice: ");
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
            insertRear(x);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            display();
            break;
        }
    } while (ch != 6);
}
