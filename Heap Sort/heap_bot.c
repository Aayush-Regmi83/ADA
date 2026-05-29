#include <stdio.h>


void heapify(int A[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;


    if (left < n && A[left] > A[largest]) {
        largest = left;
    }

    if (right < n && A[right] > A[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;


        heapify(A, n, largest);
    }
}

void buildHeap(int A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(A, n, i);
    }
}


void heapSort(int A[], int n) {

    buildHeap(A, n);


    for (int i = n - 1; i > 0; i--) {

        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;


        heapify(A, i, 0);
    }
}


void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}


int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    heapSort(A, n);

    printf("Sorted array:\n");
    printArray(A, n);

    return 0;
}
