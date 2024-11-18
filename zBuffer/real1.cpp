#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline "\n"

const int INF = LLONG_MAX >> 1;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> l1(n);
    for (int i = 0; i < n; i++) {
        cin >> l1[i];
    }

    sort(l1.begin(), l1.end());

    auto price = [&](vector<int> newl, int k) -> int {
        int count = 0;
        while (newl.size() >= k + 1) {
            count += accumulate(newl.end() - k, newl.end(), 0LL);
            newl.resize(newl.size() - k - 1);
        }
        count += accumulate(newl.begin(), newl.end(), 0LL);
        return count;
    };

    for (int i = 1; i < n; i++) {
        cout << price(vector<int>(l1.begin(), l1.begin() + i), k) << " ";
    }
    cout << price(l1, k) << newline;
}

int32_t main() {
    IOS;

    int t = 1;
    cin >> t; 
    while (t--) {
        solve();
    }

    return 0;
}
