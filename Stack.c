#include <stdio.h>

#define SIZE 50
int stack[SIZE], top = -1;

void push(int x)
{
    if (top == SIZE - 1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = x;
}

void pop()
{
    if (top == -1)
        printf("Stack Underflow!\n");
    else
        printf("Popped: %d\n", stack[top--]);
}

void peek()
{
    if (top == -1)
        printf("Stack Empty!\n");
    else
        printf("Top: %d\n", stack[top]);
}

void display()
{
    if (top == -1)
        printf("Stack Empty!\n");
    else
    {
        printf("Stack: ");
        for (int i = 0; i <= top; i++)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main()
{
    int ch, x;

    do
    {
        printf("\n1.Push  2.Pop  3.Peek  4.Display  5.Exit\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        }
    } while (ch != 5);
}
