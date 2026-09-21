#include <bits/stdc++.h>
using namespace std;

// Fast input/output to speed up cin/cout
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);

#define newline '\n' // convenience

// now, declaring an int automatically becomes long long
// This is useful for competitive programming to avoid overflow
#define int long long

// Constants often used in problems 
const int INF = 1e18;         // A large number appearing as "infinity"
const int MOD = 1e9 + 7;      // probably won't be used by yall today

// This function will be called for each test case
void solve() {
    // Example problem: read two numbers and print their sum
    int a, b;
    cin >> a >> b;
    cout << a + b << newline;
}

int32_t main() {
    IOS  // Enable fast I/O

    int t;
    // cin >> t;  // Number of test cases, if theres no mention of testcases then leave this commented out

    while (t--) {
        solve();  // call on solve() for each test case
    }

    return 0;
}
