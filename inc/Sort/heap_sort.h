#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at index `i`
// `n` is the size of the heap
void heapify(int arr[], int n, int i) {
    int largest = i;           // Initialize `largest` as the root
    int left = 2 * i + 1;       // Left child
    int right = 2 * i + 2;      // Right child

    // If the left child is larger than the root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If the right child is larger than the current largest
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest is not the root, swap and heapify the affected subtree
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Build a max-heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i >= 0; i--) {
        // Move the root (largest element) to the end
        swap(&arr[0], &arr[i]);

        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
}

#endif // HEAP_SORT_H
