#include <stdio.h>
#define NMAX 10

int input(int *a);
void copy_arr(const int *a, int *b);
void quickSort(int *a, int left, int right);
void heapSort(int *arr, int n);
void heapify(int *arr, int n, int i);
void output(int *a);

int main() {
    int data_1[NMAX];
    int data_2[NMAX];

    if (input(data_1) != 0) {
        printf("n/a");
        return 1;
    }
    copy_arr(data_1, data_2);
    quickSort(data_1, 0, NMAX - 1);
    heapSort(data_2, NMAX);
    output(data_1);
    printf("\n");
    output(data_2);
    return 0;
}

int input(int *a) {
    for (int i = 0; i < NMAX; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
    }

    if (getchar() != '\n') {
        return 1;  // check input (for example, if n = 2 but input 1 2 3 -> n/a)
    }
    return 0;
}
void copy_arr(const int *a, int *b) {
    for (int i = 0; i < NMAX; i++) {
        b[i] = a[i];
    }
}

void quickSort(int *a, int left, int right) {
    int pivot;
    int index;
    int l_hold = left;   // bordes
    int r_hold = right;  // bordes
    pivot = a[left];

    while (left < right) {
        while (left < right && a[right] > pivot) right--;  // right moves to left while
        if (left < right) {
            a[left] = a[right];
            left++;
        }
        while (left < right && a[left] < pivot) left++;  // left moves to right while a[left] < pivot
        if (left < right) {
            a[right] = a[left];
            right--;  // right moves to left
        }
    }
    a[left] = pivot;
    index = left;

    // back to original bordes
    left = l_hold;
    right = r_hold;

    // work with subarrays
    if (left < index) quickSort(a, left, index - 1);
    if (right > index) quickSort(a, index + 1, right);
}

void heapSort(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void heapify(int *arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;
        heapify(arr, n, largest);
    }
}

void output(int *a) {
    for (int i = 0; i < NMAX - 1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d", a[9]);
}