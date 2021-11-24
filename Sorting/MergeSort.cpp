#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &numbers, int left, int middle, int right) {
  int n1 = middle - left + 1;
  int n2 = right - middle;
  int a[n1], b[n2];

  // loop through both sub arrays
  for (int i = 0; i < n1; i++) {
        a[i] = numbers[left + i];
  }
  for(int i = 0; i < n2; i++) {
        b[i] = numbers[middle + 1 + i];
  }

  int i = 0, j = 0, k = left;

  while(i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            numbers[k++] = a[i++];
        } else {
            numbers[k++] = b[j++];
        }
    }

    while(i < n1) {
        numbers[k++] = a[i++];
    }
    while(j < n2) {
        numbers[k++] = b[j++];
    }
}

void mergeSort(vector<int> &numbers, int left, int right) {
  if (left >= right) {
    return;
  }

  int mid = left + (right - left)/2;
  // recursively sort
  mergeSort(numbers, left, mid);
  mergeSort(numbers, mid + 1, right);
  merge(numbers, left, mid, right);

}

vector<int> sortArray(vector<int> &numbers) {
    mergeSort(numbers, 0, numbers.size() - 1);
    return numbers;
}  

void printVector(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v.at(i) << " ";
  }
}

int main() {
  vector<int> values;
  int user_option, ele;

  cout << "Enter a number of array elements: ";
  cin >> ele;

  for (int i = 0; i < ele; i++) {
    cout << "Enter a number: ";
    cin >> user_option;
    values.push_back(user_option);
  }

  sortArray(values);
  printVector(values);
} 
