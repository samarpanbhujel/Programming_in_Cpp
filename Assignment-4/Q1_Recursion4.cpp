// Recursive Binary Search
#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key) {

    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;

    if (key < arr[mid])
        return binarySearch(arr, low, mid - 1, key);

    return binarySearch(arr, mid + 1, high, key);
}

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;

    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result == -1)
        cout << "Element not found." << endl;
    else
        cout << "Element found at index "
             << result << endl;

    return 0;
}