#include <stdio.h>

int binarySearch(int arr[], int n, int key)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    printf("Enter number of elements (sorted ascending): ");
    if (scanf("%d", &n) != 1)
        return 0;
    int arr[n];
    printf("Enter %d sorted integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int key;
    printf("Enter key to search: ");
    scanf("%d", &key);

    int idx = binarySearch(arr, n, key);
    if (idx != -1)
        printf("Found at index %d (0-based)\n", idx);
    else
        printf("Not found\n");
    return 0;
}
