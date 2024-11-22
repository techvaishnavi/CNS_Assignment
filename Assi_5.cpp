#include <iostream>
#include <string>
using namespace std;

string railFenceCipher(string text, int key) {
    string result = "";
    char rail[key][text.length()];
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < text.length(); j++) {
            rail[i][j] = '\n';
        }
    }

    int row = 0, col = 0;
    bool down = false;
    for (int i = 0; i < text.length(); i++) {
        rail[row][col++] = text[i];
        if (row == 0 || row == key - 1) down = !down;
        row += down ? 1 : -1;
    }

    for (int i = 0; i < key; i++) {
        for (int j = 0; j < text.length(); j++) {
            if (rail[i][j] != '\n') result += rail[i][j];
        }
    }
    return result;
}

int main() {
    string text;
    int key;
    
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter key: ";
    cin >> key;
    
    string encrypted = railFenceCipher(text, key);
    cout << "Encrypted text: " << encrypted << endl;
    
    return 0;
}

