#include <bits/stdc++.h>
using namespace std;

// Reads: n, then n lines of "ai di" (HHMM integers).
// Outputs: minimum number of platforms needed.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> arr(n), dep(n);
    for (int i = 0; i < n; ++i) {
        int a, d;
        cin >> a >> d;
        arr[i] = a;
        dep[i] = d;
    }

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 0, j = 0;
    int cur = 0, need = 0;

    // Tie rule: departure frees platform before any arrival at the same minute.
    while (i < n && j < n) {
        if (arr[i] < dep[j]) {
            ++cur;                 // a train arrives before next departure
            need = max(need, cur);
            ++i;
        } else {
            --cur;                 // departure first (also handles arr[i] == dep[j])
            ++j;
        }
    }

    cout << need << '\n';
    return 0;
}
