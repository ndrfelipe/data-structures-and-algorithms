#include <iostream>
using namespace std;

void selectionSort(int arr[], int s){

    for( int i = 0 ; i < s - 1 ; i++ ) {
        int min_idx = i;
        for( int j = i + 1 ; j < s ; j++ ) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }

            int temp     = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i]       = temp;
        }   
    }
}

int main() {
    int vector[] = {6, 10, 9, 1, 4, 3, 2, 5, 7, 8};
    int size = 10;
    selectionSort(vector, size);

    cout << "\nArray ordenado selectionSort: \n";
    for (int i = 0; i < size; i++)
        cout << vector[i];
}