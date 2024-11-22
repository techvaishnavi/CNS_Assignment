#include <iostream>
using namespace std;

string caesarCipher(string text, int shift) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            result += char(int(base + (text[i] - base + shift) % 26));
        } else {
            result += text[i];  // Non-alphabetic characters are added as is
        }
    }
    return result;
}

int main() {
    string text;
    int shift;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter shift value: ";
    cin >> shift;
    
    string encrypted = caesarCipher(text, shift);
    cout << "Encrypted Text: " << encrypted << endl;
    
    return 0;
}

