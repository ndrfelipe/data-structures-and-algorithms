#include <iostream>
using namespace std;

void bubbleSort(int arr[], int s){
    for( int i = 0 ; i < s - 1 ; i++ ) {
        for ( int j = 0 ; j < s- i - 1 ; j++ ) {
            if ( arr[j] > arr[ j + 1 ] ) {
                int temp   = arr[j];
                arr[j]     = arr[j + 1];
                arr[j + 1] = temp;
                
            }
        }
        
    }
}

int main() {
    int vector[] = {6, 10, 9, 1, 4, 3, 2, 5, 7, 8};
    int size = 10;
    bubbleSort(vector, size);

    cout << "\nArray ordenado bubbleSort: \n";
    for (int i = 0; i < size; i++)
        cout << vector[i];
}