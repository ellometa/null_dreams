#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        cin >> N;

        if (N == 0) {
            cout << 0 << "\n";
            continue;
        }

        bool first = true;
        while (N > 0) {
            int digit = N % 10;
            if (!first) cout << ' ';
            cout << digit;
            first = false;
            N /= 10;
        }
        cout << "\n";
    }
    return 0;
}
