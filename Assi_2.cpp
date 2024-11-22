#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string formatText(string text) {
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == 'j') {
            text[i] = 'i';
        }
    }
    if (text.length() % 2 != 0) {
        text += 'x';
    }
    return text;
}

void createMatrix(string key, char matrix[5][5]) {
    bool used[26] = {false};
    int row = 0, col = 0;
    
    for (int i = 0; i < key.length(); i++) {
        if (key[i] != 'j' && !used[key[i] - 'a']) {
            matrix[row][col] = key[i];
            used[key[i] - 'a'] = true;
            col++;
            if (col == 5) {
                col = 0;
                row++;
            }
        }
    }

    for (char c = 'a'; c <= 'z'; c++) {
        if (!used[c - 'a'] && c != 'j') {
            matrix[row][col] = c;
            col++;
            if (col == 5) {
                col = 0;
                row++;
            }
        }
    }
}

string encrypt(string text, char matrix[5][5]) {
    string encrypted = "";
    for (int i = 0; i < text.length(); i += 2) {
        int row1, col1, row2, col2;
        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                if (matrix[r][c] == text[i]) {
                    row1 = r;
                    col1 = c;
                }
                if (matrix[r][c] == text[i + 1]) {
                    row2 = r;
                    col2 = c;
                }
            }
        }

        if (row1 == row2) {
            encrypted += matrix[row1][(col1 + 1) % 5];
            encrypted += matrix[row2][(col2 + 1) % 5];
        } else if (col1 == col2) {
            encrypted += matrix[(row1 + 1) % 5][col1];
            encrypted += matrix[(row2 + 1) % 5][col2];
        } else {
            encrypted += matrix[row1][col2];
            encrypted += matrix[row2][col1];
        }
    }
    return encrypted;
}

int main() {
    string key = "ldrp";
    string text;
    cout << "Enter text: ";
    getline(cin, text);
    
    text = formatText(text);
    
    char matrix[5][5];
    createMatrix(key, matrix);
    
    string encrypted = encrypt(text, matrix);
    cout << "Encrypted text: " << encrypted << endl;
    
    return 0;
}

