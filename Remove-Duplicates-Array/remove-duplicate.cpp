#include <iostream>
using namespace std;

int remove_dup(int arr[], int n) {
    if (n == 0) return 0; // Edge case: Empty array

    int x = 0; // Index to store unique elements

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[x]) { // Check if element is different
            x++; 
            arr[x] = arr[i]; // Move unique element forward
        }
    }

    return x + 1; // New size of the array
}

void printarr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Before removing duplicates: ";
    printarr(arr, n);
    cout << endl;

    int new_size = remove_dup(arr, n); // Remove duplicates

    cout << "After removing duplicates: ";
    printarr(arr, new_size);
    cout << endl;

    return 0;
}
