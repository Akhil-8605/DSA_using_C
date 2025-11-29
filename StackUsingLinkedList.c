#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int x)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack Empty!\n");
        return;
    }
    printf("Popped: %d\n", top->data);
    struct Node *t = top;
    top = top->next;
    free(t);
}

void display()
{
    struct Node *t = top;
    printf("Stack: ");
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
        printf("\n1.Push 2.Pop 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Value: ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        }
    } while (ch != 4);
}
