#include <iostream>

using namespace std;

int main() {
    
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int multiArray[rows][cols];

    // Input //
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element for position [" << i << "][" << j << "]: ";
            cin >> multiArray[i][j];
        }
    }

    // Output //
    cout << "Contents of the array:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << multiArray[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
