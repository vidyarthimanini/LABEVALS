#include <iostream>
#include <vector>
using namespace std;

void countingSort(int arr[], int n, int max_value) {
    // Create a count array to store the frequency of each element
    vector<int> count(max_value + 1, 0);

    // Count the occurrences of each element in the input array
    for (int i = 0; i < n; ++i) {
        count[arr[i]]++;
    }

    // Update the count array to store the cumulative frequency
    for (int i = 1; i <= max_value; ++i) {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store the sorted output
    int output[n];

    // Build the output array by placing elements in their correct positions
    for (int i = n - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted output back to the original array
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements (0 to max_value):" << endl;

    int max_value = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        max_value = max(max_value, arr[i]);
    }

    cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    countingSort(arr, n, max_value);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

