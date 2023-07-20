#include <iostream>
using namespace std;

void shellSort(int arr[], int n) {
    // Start with a big gap and reduce it in each iteration
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform insertion sort on elements at each gap
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j = i;

            // Shift elements that are greater than temp to the right
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
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

    shellSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
