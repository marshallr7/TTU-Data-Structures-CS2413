#include <iostream>

using namespace std;

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
  
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

bool isSorted(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    if (i != n-1 && !(arr[i] < arr[i + 1])) {
      return false;
    }
  }
  return true;
}

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    if (i != n-1 && arr[i] > arr[i + 1]) {
      swap(&arr[i], &arr[i + 1]);
    }
  }
  if (!isSorted(arr, n)) {
    return bubbleSort(arr, n);
  }
}

int main() {
  int arr[] = {64, 1, 16, 92, 43, 87, 100};
  int n = sizeof(arr)/sizeof(arr[0]);

  bubbleSort(arr, n);
  printArray(arr, n);
}
