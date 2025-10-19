#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve() {
    int n = 600851475143;
    cout << "Prime factors of " << n << ":" newline;

    // Check for divisibility by 2 first
    while (n % 2 == 0) {
        cout << 2 newline;
        n /= 2;
    }

    // Check for odd factors from 3 to sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i newline;
            n /= i;
        }
    }

    // If n is still greater than 1, it is a prime number
    if (n > 1) {
        cout << n newline;
    }
}

int32_t main() {
    IOS;

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
