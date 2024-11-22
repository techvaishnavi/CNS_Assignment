#include <iostream>
#include <bitset>
using namespace std;

// S-Boxes and key generation would typically go here.
// For simplification, we will assume predefined S-Boxes.

string sdes(string plaintext, string key) {
    // Simulating DES encryption (this is just a simplified mockup)
    bitset<8> pt(plaintext);
    bitset<8> k(key);

    // Simple substitution example (would typically involve several rounds)
    return (pt ^ k).to_string();
}

int main() {
    string plaintext, key;
    cout << "Enter plaintext (8 bits): ";
    cin >> plaintext;
    cout << "Enter key (8 bits): ";
    cin >> key;
    
    string encrypted = sdes(plaintext, key);
    cout << "Encrypted text: " << encrypted << endl;
    
    return 0;
}

