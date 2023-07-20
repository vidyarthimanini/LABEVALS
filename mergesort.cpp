#include <iostream>
using namespace std;

// Function to merge two sorted subarrays into one sorted array
void merge(int arr[], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    // Create temporary arrays to store the left and right subarrays
    int leftArr[leftSize];
    int rightArr[rightSize];

    // Copy data to temporary arrays
    for (int i = 0; i < leftSize; ++i) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < rightSize; ++i) {
        rightArr[i] = arr[mid + 1 + i];
    }

    // Merge the two temporary arrays back into the original array
    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    // Copy any remaining elements from the left and right subarrays
    while (i < leftSize) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }
    while (j < rightSize) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
