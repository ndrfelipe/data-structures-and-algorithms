#include <iostream>
using namespace std;

void insertionSort(int arr[], int s){
    int i, key, j;

    for( i = 1 ; i < s ; i++ ) {
       key = arr[i];
       j = i - 1;

       while( j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
       }
       arr[j+1] = key;
    }
}

int main() {
    int vector[] = {6, 10, 9, 1, 4, 3, 2, 5, 7, 8};
    int size = 10;
    insertionSort(vector, size);

    cout << "\nArray ordenado insertionSort: \n";
    for (int i = 0; i < size; i++)
        cout << vector[i];
}