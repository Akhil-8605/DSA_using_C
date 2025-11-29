#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i; // return index
    return -1;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int key;
    printf("Enter key to search: ");
    scanf("%d", &key);

    int idx = linearSearch(arr, n, key);
    if (idx != -1) printf("Found at index %d (0-based)\n", idx);
    else printf("Not found\n");
    return 0;
}
