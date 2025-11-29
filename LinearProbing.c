#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

void init()
{
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hash(int key)
{
    return key % SIZE;
}

void insert(int key)
{
    int index = hash(key);
    int start = index;

    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;
        if (index == start)
        {
            printf("Hash table full!\n");
            return;
        }
    }
    hashTable[index] = key;
}

void search(int key)
{
    int index = hash(key);
    int start = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            printf("Found at index %d\n", index);
            return;
        }
        index = (index + 1) % SIZE;
        if (index == start)
            break;
    }
    printf("Not found\n");
}

void display()
{
    for (int i = 0; i < SIZE; i++)
        printf("%d → %d\n", i, hashTable[i]);
}

int main()
{
    init();
    int choice, key;

    do
    {
        printf("\n1.Insert  2.Search  3.Display  4.Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key: ");
            scanf("%d", &key);
            insert(key);
            break;
        case 2:
            printf("Enter key: ");
            scanf("%d", &key);
            search(key);
            break;
        case 3:
            display();
            break;
        }
    } while (choice != 4);
}
