#include <stdio.h>
#include <stdint.h>

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int* arr, int size, int num) {
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;    
        if (num == arr[mid]) {
            return mid;
        }

        else if (num < arr[mid]) {
            high = mid - 1;
        }

        else {
            low = mid + 1;
        }
    }

    return -1;
}
int arraySortedOrNot(int arr[], int n)
{
    if (n == 1 || n == 0)
        return 1;
    if (arr[n - 1] < arr[n - 2])
        return 0;

    return arraySortedOrNot(arr, n - 1);
}
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {

        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 ,5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x ;
    printf("what number do you want to search ? ");
    scanf_s("%d", &x);
    int result;
    if (arraySortedOrNot(arr, n)){
        result = binarySearch(arr, n, x);
    }
    else
    {
        selectionSort(arr,n);
        result = binarySearch(arr, n, x);
    }
     (result == -1) ? printf("Element is not present in array"): printf("Element is present at index %d", result);
    
    return 0;
}
