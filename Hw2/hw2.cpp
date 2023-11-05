#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// function to calculate gcd of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// function to calculate modular inverse of a number
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

// function to decode the message
string decodeMessage(string cypher, int e, int n) {
    string plaintext = "";
    int m = cypher.length();
    for (int i = 0; i < m; i++) {
        int c = cypher[i] - '0';
        int p = pow(c, e);
        p = p % n;
        plaintext += to_string(p);
    }
    return plaintext;
}

int main() {
    int e, n, m;
    string cypher;
    cin >> e >> n >> m >> cypher;

    // check if public key is valid
    if (!isPrime(n)) {
        cout << "Public key is not valid!" << endl;
        return 0;
    }

    // calculate p and q
    int p = 0, q = 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            p = i;
            q = n / i;
            break;
        }
    }

    // calculate theta(n)
    int theta = (p - 1) * (q - 1);

    // calculate d
    int d = modInverse(e, theta);

    // decode the message
    string plaintext = decodeMessage(cypher, d, n);

    // output p, q, theta(n), and d
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    cout << "theta(n): " << theta << endl;
    cout << "d: " << d << endl;

    // output decoded message in integers
    cout << "Decoded message (integers): " << plaintext << endl;

    // output decoded message in English
    string english = "";
    int len = plaintext.length();
    for (int i = 0; i < len; i += 2) {
        int num = stoi(plaintext.substr(i, 2));
        char c = num + 4 + 'A';
        english += c;
    }
    cout << "Decoded message (English): " << english << endl;

    return 0;
}
