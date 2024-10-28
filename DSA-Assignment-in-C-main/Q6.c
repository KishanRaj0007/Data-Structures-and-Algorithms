#include <stdio.h>
#include <stdlib.h>

int* merge(int a[], int sizeA, int b[], int sizeB) {
    int* result = (int*)malloc((sizeA + sizeB) * sizeof(int));
    int indexA = 0, indexB = 0, index = 0;

    while (indexA < sizeA && indexB < sizeB) {
        if (a[indexA] < b[indexB]) {
            result[index] = a[indexA];
            indexA++;
        } else {
            result[index] = b[indexB];
            indexB++;
        }
        index++;
    }
    
    //suppose any one array gets exhausted then insert rest at end as it is
    while (indexA < sizeA) {
        result[index] = a[indexA];
        indexA++;
        index++;
    }

    while (indexB < sizeB) {
        result[index] = b[indexB];
        indexB++;
        index++;
    }

    return result;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {7, 9, 12};
    int b[] = {1, 8, 11, 15};
    int size1 = sizeof(a) / sizeof(int);
    int size2 = sizeof(b) / sizeof(int);
    printf("First array is: ");
    printArray(a, size1);
    printf("Second array is: ");
    printArray(b, size2);
    printf("Final array after merging is: ");
    int* mergedArray = merge(a, size1, b, size2);
    printArray(mergedArray, size1 + size2);
    free(mergedArray); // Free dynamically allocated memory
    return 0;
}
