#include <iostream>
#include <string>
using namespace std;

string vigenereCipher(string text, string key) {
    string result = "";
    int keyIndex = 0;
    
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char k = key[keyIndex % key.length()];
            char keyBase = isupper(k) ? 'A' : 'a';
            
            result += char(int(base + (c - base + (k - keyBase)) % 26));
            keyIndex++;
        } else {
            result += c;  // Non-alphabet characters remain unchanged
        }
    }
    return result;
}

int main() {
    string text, key;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter key: ";
    getline(cin, key);
    
    string encrypted = vigenereCipher(text, key);
    cout << "Encrypted text: " << encrypted << endl;
    
    return 0;
}

