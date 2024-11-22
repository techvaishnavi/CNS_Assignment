#include <iostream>
using namespace std;

// AES simplification
string aesEncrypt(string plaintext, string key) {
    // This is a very simplified approach for AES encryption
    string ciphertext = "";
    for (int i = 0; i < plaintext.length(); i++) {
        ciphertext += char(plaintext[i] ^ key[i % key.length()]);
    }
    return ciphertext;
}

int main() {
    string plaintext, key;
    cout << "Enter plaintext: ";
    getline(cin, plaintext);
    cout << "Enter key: ";
    getline(cin, key);
    
    string encrypted = aesEncrypt(plaintext, key);
    cout << "Encrypted text: " << encrypted << endl;
    
    return 0;
}

