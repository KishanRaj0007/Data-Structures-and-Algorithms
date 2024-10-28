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
    int arr[] = {2, 3, 7, 6, 8, -1, -10, 6};
    int count = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,count);
    int flag = 0;
    for (int i = 0; i < count - 1; i++) {
        if(arr[i] == arr[i+1]){
            printf("First repeating element in array is %d",arr[i]);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("All elements in aray are unique");
    }
    
}