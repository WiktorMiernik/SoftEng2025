
#include "Select.h"
using namespace std;

// n powinno byc liczba elementow tablicy
// np. int n = sizeof(arr) / sizeof(arr[0]);

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}