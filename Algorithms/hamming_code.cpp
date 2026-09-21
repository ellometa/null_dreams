#include <bits/stdc++.h>
using namespace std;

int findR(int m) {
    int r = 0;
    while (pow(2, r) < m + r + 1)
        r++;
    return r;
}

void encode() {
    string data;
    cout << "Enter data bits: ";
    cin >> data;

    int m = data.length();
    int r = findR(m);
    int n = m + r;

    vector<char> code(n + 1);
    int j = 0;
    for (int i = 1; i <= n; i++) {
        if ((i & (i - 1)) == 0) {
            code[i] = '0';
        } else {
            code[i] = data[j];
            j++;
        }
    }

    for (int i = 0; i < r; i++) {
        int pos = pow(2, i);
        int parity = 0;
        for (int k = 1; k <= n; k++) {
            if (k & pos)
                parity ^= (code[k] - '0');
        }
        code[pos] = parity + '0';
    }

    cout << "Hamming code: ";
    for (int i = 1; i <= n; i++)
        cout << code[i];
    cout << endl;
}

void decode() {
    string code;
    cout << "Enter received code: ";
    cin >> code;

    int n = code.length();
    vector<char> w(n + 1);
    for (int i = 1; i <= n; i++)
        w[i] = code[i - 1];

    int r = 0;
    while (pow(2, r) < n + 1)
        r++;

    int error = 0;
    for (int i = 0; i < r; i++) {
        int pos = pow(2, i);
        int parity = 0;
        for (int k = 1; k <= n; k++) {
            if (k & pos)
                parity ^= (w[k] - '0');
        }
        if (parity != 0)
            error += pos;
    }

    if (error == 0) {
        cout << "No error" << endl;
    } else {
        cout << "Error at position " << error << endl;
        w[error] = (w[error] == '0') ? '1' : '0';
        cout << "Corrected: ";
        for (int i = 1; i <= n; i++)
            cout << w[i];
        cout << endl;
    }
}

int main() {
    int ch;
    cout << "1. Encode\n2. Decode\n";
    cin >> ch;

    if (ch == 1)
        encode();
    else if (ch == 2)
        decode();
    else
        cout << "Invalid" << endl;

    return 0;
}