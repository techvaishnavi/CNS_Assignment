#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string columnarTransposition(string text, string key) {
    int n = key.length();
    int rows = (text.length() + n - 1) / n;
    vector<vector<char>> matrix(rows, vector<char>(n, ' '));
    
    // Fill the matrix with the text
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < n && k < text.length(); j++) {
            matrix[i][j] = text[k++];
        }
    }
    
    // Create a map of column indices based on key order
    vector<pair<int, char>> keyOrder;
    for (int i = 0; i < key.length(); i++) {
        keyOrder.push_back({key[i] - '0', key[i]});
    }
    sort(keyOrder.begin(), keyOrder.end());
    
    // Read the columns in the order of sorted key
    string encrypted = "";
    for (int i = 0; i < n; i++) {
        int col = keyOrder[i].first;
        for (int j = 0; j < rows; j++) {
            if (matrix[j][col] != ' ') {
                encrypted += matrix[j][col];
            }
        }
    }
    return encrypted;
}

int main() {
    string text, key;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter key: ";
    getline(cin, key);
    
    string encrypted = columnarTransposition(text, key);
    cout << "Encrypted text: " << encrypted << endl;
    
    return 0;
}

