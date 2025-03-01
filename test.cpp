#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Caesar Cipher Implementation
string caesarCipherEncrypt(string text, int shift) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            char offset = isupper(c) ? 'A' : 'a';
            result += char(int(c + shift - offset) % 26 + offset);
        } else {
            result += c;
        }
    }
    return result;
}

string caesarCipherDecrypt(string text, int shift) {
    return caesarCipherEncrypt(text, 26 - shift); // Reverse shift
}

// Function to compute greatest common divisor
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// RSA Key Generation
void generateRSAKeys(int &e, int &d, int &n) {
    int p = 61, q = 53; // Two prime numbers
    n = p * q;
    int phi = (p - 1) * (q - 1);
    
    e = 3;
    while (gcd(e, phi) != 1) {
        e += 2;
    }
    
    d = 1;
    while ((d * e) % phi != 1) {
        d++;
    }
}

// RSA Encryption
int rsaEncrypt(int message, int e, int n) {
    int encrypted = 1;
    for (int i = 0; i < e; i++) {
        encrypted = (encrypted * message) % n;
    }
    return encrypted;
}

// RSA Decryption
int rsaDecrypt(int encrypted, int d, int n) {
    int decrypted = 1;
    for (int i = 0; i < d; i++) {
        decrypted = (decrypted * encrypted) % n;
    }
    return decrypted;
}

int main() {
    cout << "Cryptography Tool\n";
    
    // Caesar Cipher Demo
    string text;
    int shift;
    cout << "Enter text for Caesar Cipher: ";
    getline(cin, text);
    cout << "Enter shift value: ";
    cin >> shift;
    string encryptedText = caesarCipherEncrypt(text, shift);
    cout << "Encrypted Text: " << encryptedText << endl;
    cout << "Decrypted Text: " << caesarCipherDecrypt(encryptedText, shift) << endl;
    
    // RSA Demo
    int e, d, n;
    generateRSAKeys(e, d, n);
    cout << "\nRSA Key Pair (Public: " << e << ", " << n << ", Private: " << d << ")\n";
    
    int message;
    cout << "Enter a number to encrypt using RSA: ";
    cin >> message;
    int encryptedRSA = rsaEncrypt(message, e, n);
    cout << "Encrypted Message: " << encryptedRSA << endl;
    cout << "Decrypted Message: " << rsaDecrypt(encryptedRSA, d, n) << endl;
    
    return 0;
}
