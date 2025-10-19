#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {
    
    
    vector<int> v = {1, 2, 3, 4, 5};

    // Try finding the value 10 in the vector
    
    auto it = find(v.begin(), v.end(), 10);

    if (it != v.end()) {
        cout << "Found 10 at position: " << distance(v.begin(), it) << endl;
    } else {
        cout << "10 not found in the vector." << endl;
    }

    return 0;
}

    
}

int32_t main() {
    IOS;

    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}