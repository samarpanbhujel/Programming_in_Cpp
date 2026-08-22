// Linear Search Using Recursion
#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key, int index) {

    // Element not found
    if (index == n)
        return -1;

    // Element found
    if (arr[index] == key)
        return index;

    // Search next element
    return linearSearch(arr, n, key, index + 1);
}

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;

    cout << "Enter element to search: ";
    cin >> key;

    int result = linearSearch(arr, n, key, 0);

    if (result == -1)
        cout << "Element not found." << endl;
    else
        cout << "Element found at index "
             << result << endl;

    return 0;
}