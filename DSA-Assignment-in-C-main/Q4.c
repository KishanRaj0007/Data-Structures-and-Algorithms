#include<stdio.h>
#include <stdbool.h>
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

int main()
{
    int arr[] = {2, 3, 7, 6, 8, -1, -10, 15};
    int count = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,count);
    int start = 0;
    for (int i = 0; i < count; i++) {
        if(arr[i] > 0)
        {
            start = i;
            break;
        }
    }
    printf("Given array is : \n");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 1; i < count; i++) {
        if(arr[start] == i)
        {
            start = start+1;
            continue;
        }
        else
        {
            printf("The smallest positive integer missing from array is %d ",i);
            break;
        }
    }
}