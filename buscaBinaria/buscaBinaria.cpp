#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool startWithPrefixValue(const string &title, const string&prefix) {
    return title.rfind(prefix, 0) == 0;
} 

int binarySearchPrefix(string vector[], int size, string prefix) {
    int min = 0, max = size - 1, middle;

    while (min <= max) {
        middle = (min + max) / 2;
        if (vector[middle].compare(0, prefix.size(), prefix) == 0) {
            return middle;
        }else if(vector[middle] < prefix) {
            min = middle + 1;
        }else {
            max = middle - 1;
        }
    }

    return -1;
}

vector<string> searchByPrefix(string vector[], int size, string prefix) {
    std::vector<string> results;
    
    // O(log n)
    int position = binarySearchPrefix(vector, size, prefix);

    if (position == -1) {
        return results;
    }
    
    // O(k) -- where 'k' is the number of adjacent results.
    int leftPosition = position;
    while (leftPosition >= 0 && startWithPrefixValue(vector[leftPosition], prefix)) {
        leftPosition--;
    }

    int rightPosition = position;
    while (rightPosition < size && startWithPrefixValue(vector[rightPosition], prefix)) {
        rightPosition++;
    }

    for (int k = leftPosition + 1; k < rightPosition; k++) {
        results.push_back(vector[k]);
    }

    return results;
}


int main(){
    string books[] = {
        "Aprendendo C",
        "Banco de Dados",
        "C Completo",
        "Harpa Crista",
        "Harry Potter",
        "Java Facil",
        "Python Basico"
    };

    int size     = sizeof(books) / sizeof(books[0]);
    string prefix    = "Har";

    std::vector<string> foundBooks = searchByPrefix(books, size, prefix);

    cout<<"Books founded using prefix search '" << prefix <<"' : "  << endl;
    if (foundBooks.empty()) {
        cout << "None books" << endl;
    } else {
        for (const string &title : foundBooks ) {
            cout << " - " << title << endl;
        }
    }

    return 0;
}