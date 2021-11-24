#include <iostream>
#include <vector>

using namespace std;

//
// HELPERS
//
void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
  
}

void printArray(int arr[], int n) {
  cout << "\nArray Contents: \n";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

bool isSorted(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    if (i != n-1 && !(arr[i] < arr[i + 1])) {
      return false;
    }
  }
  return true;
}

//
// SORTING METHODS
//

void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int j = i;
    while (arr[j] < arr[j-1]) {
      swap(arr[j], arr[j-1]);
      j--;
    }
  }
}

void selectionSort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    int minIndex = i;
    for (int j = i+1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    swap(arr[minIndex], arr[i]);
  }
}

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    if (i != n-1 && arr[i] > arr[i + 1]) {
      swap(arr[i], arr[i + 1]);
    }
  }
  if (!isSorted(arr, n)) {
    return bubbleSort(arr, n);
  }
}

// 
// MAIN MENU
//

int menu() {
  int option;
  cout << "Input Data (0), Insertion Sort (1), Selection Sort (2), Bubble Sort (3), Quick Sort (4), Radix Sort (5), Exit Program (6)";
  cout << "\nEnter an option: ";
  cin >> option;
  return option;
}

int main() {
  int userOption;
  
  int arr[] = {64, 1, 16, 92, 43, 87, 100};
  int n = sizeof(arr)/sizeof(arr[0]);
  int a[n];

  while (userOption != 6) {

    userOption = menu();

    if (userOption == 6) {
      return 0;
    }

    // duplicate main array so we don't have to keep re-entering content
    copy(begin(arr), end(arr), a);

    switch (userOption) {
      case 0:
        break;
      case 1:
        insertionSort(a, n);
      case 2:
        selectionSort(a, n);
        break;
      case 3:
        bubbleSort(a, n);
        break;
      case 4:
        // quick Sort
        break;
      case 5:
        // bucket Sort
        break;
      default:
        cout << "\nError... Something went wrong.";
        break;
    }
    printArray(a, n);
  }

} 
