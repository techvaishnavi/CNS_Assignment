#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> inverseMatrix(vector<vector<int>> matrix) {
    // Inverse of a 2x2 matrix
    int determinant = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    int invDet = 1;
    for (int i = 1; i < 26; i++) {
        if ((determinant * i) % 26 == 1) {
            invDet = i;
            break;
        }
    }

    vector<vector<int>> invMatrix(2, vector<int>(2));
    invMatrix[0][0] = (matrix[1][1] * invDet) % 26;
    invMatrix[0][1] = (-matrix[0][1] * invDet) % 26;
    invMatrix[1][0] = (-matrix[1][0] * invDet) % 26;
    invMatrix[1][1] = (matrix[0][0] * invDet) % 26;
    
    return invMatrix;
}

vector<int> multiplyMatrix(vector<vector<int>> matrix, vector<int> vec) {
    vector<int> result(2);
    for (int i = 0; i < 2; i++) {
        result[i] = (matrix[i][0] * vec[0] + matrix[i][1] * vec[1]) % 26;
    }
    return result;
}

string hillCipher(string text, vector<vector<int>> matrix) {
    string encrypted = "";
    for (int i = 0; i < text.length(); i += 2) {
        vector<int> vec(2);
        vec[0] = text[i] - 'a';
        vec[1] = text[i + 1] - 'a';
        
        vector<int> enc = multiplyMatrix(matrix, vec);
        
        encrypted += char(enc[0] + 'a');
        encrypted += char(enc[1] + 'a');
    }
    return encrypted;
}

int main() {
    string text;
    vector<vector<int>> matrix = {{6, 24}, {1, 16}};  // Example matrix
    
    cout << "Enter text: ";
    getline(cin, text);
    
    text = text.substr(0, text.length() - text.length() % 2); // Ensure even length
    
    string encrypted = hillCipher(text, matrix);
    cout << "Encrypted text: " << encrypted << endl;
    
    return 0;
}

