#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void generateUniqueRandomNumbers(int arr[], int size) {
    int num, i = 0, j;
    while (i < size) {
        num = rand() % 100 + 1; // 1 ~ 100 범위에서 생성
        for (j = 0; j < i; j++) {
            if (arr[j] == num) break;
        }
        if (j == i) arr[i++] = num;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// 선택정렬
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[min]) min = j;
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

// 버블정렬
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

// 퀵정렬
void quickSort(int arr[], int left, int right) {
    if (left >= right) return;
    int pivot = arr[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++; j--;
        }
    }
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

// 삽입정렬
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

void copyArray(int dest[], int src[], int size) {
    for (int i = 0; i < size; i++)
        dest[i] = src[i];
}

int main() {
    srand(time(NULL));
    int original[SIZE];
    int arr[SIZE];

    generateUniqueRandomNumbers(original, SIZE);
    printf("원본 데이터: ");
    printArray(original, SIZE);

    copyArray(arr, original, SIZE);
    selectionSort(arr, SIZE);
    printf("선택 정렬: ");
    printArray(arr, SIZE);

    copyArray(arr, original, SIZE);
    bubbleSort(arr, SIZE);
    printf("버블 정렬: ");
    printArray(arr, SIZE);

    copyArray(arr, original, SIZE);
    quickSort(arr, 0, SIZE - 1);
    printf("퀵 정렬: ");
    printArray(arr, SIZE);

    copyArray(arr, original, SIZE);
    insertionSort(arr, SIZE);
    printf("삽입 정렬: ");
    printArray(arr, SIZE);

    return 0;
}
