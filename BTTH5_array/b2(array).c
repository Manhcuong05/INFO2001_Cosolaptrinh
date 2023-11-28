#include <stdio.h>
#include <time.h>

int linearSearch(int arr[], int a, int b) {
    int i;
    for (i = 0; i < a; i++) {
        if (arr[i] == b) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int low, int high, int b) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == b) {
            return mid;
        }
        if (arr[mid] >b) {
            return binarySearch(arr, low, mid - 1, b);
        }
        return binarySearch(arr, mid + 1, high, b);
    }
    return -1;
}

int main() {
    int arr[1000];
    int a = sizeof(arr) / sizeof(arr[0]);
    int i, x;

    for (i = 0; i < a; i++) {
        arr[i] = i;
    }

    clock_t start_linear = clock();
    x = linearSearch(arr, a, a + 1);
    clock_t end_linear = clock();
    double time_linear = (double)(end_linear - start_linear) / CLOCKS_PER_SEC;

    clock_t start_binary = clock();
    x = binarySearch(arr, 0, a - 1, a + 1);
    clock_t end_binary = clock();
    double time_binary = (double)(end_binary - start_binary) / CLOCKS_PER_SEC;
    printf("thoi gian thuc hien Linear Search: %f giay\n", time_linear);
    printf("thoi gian thuc hien Binary Search: %f giay\n", time_binary);
    return 0;
}