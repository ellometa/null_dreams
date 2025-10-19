#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;

    if (N == 1) {
        cout << 1 << "\n1\n";
        return 0;
    }

    long long k = N / 2;
    cout << k << '\n';
    for (long long x = 2, i = 0; x <= N; x += 2, ++i) {
        if (i) cout << ' ';
        cout << x;
    }
    cout << '\n';
    return 0;
}
