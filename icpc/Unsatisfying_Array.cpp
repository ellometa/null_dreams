#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline << '\n'
#define all(x) (x).begin(), (x).end()
const int INF = LLONG_MAX >> 1;

void solve() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N, N); // Initialize array A with N
        vector<tuple<int, int, int>> constraints(K);

        for (int i = 0; i < K; ++i) {
            int L, R, m;
            cin >> L >> R >> m;
            constraints[i] = make_tuple(L - 1, R - 1, m); // Convert 1-based to 0-based indexing
        }

        bool valid = true;

        for (int i = 0; i < K; ++i) {
            int L = get<0>(constraints[i]);
            int R = get<1>(constraints[i]);
            int m = get<2>(constraints[i]);

            bool found = false;
            for (int j = L; j <= R; ++j) {
                if (A[j] == m) {
                    // Change it to something not equal to m
                    A[j] = (m != 1) ? 1 : N;
                }
                if (A[j] != m) {
                    found = true;
                }
            }
            if (!found) {
                valid = false;
                break;
            }
        }

        if (valid) {
            for (int i = 0; i < N; ++i) {
                cout << A[i] << " ";
            }
            cout newline;
        } else {
            cout << -1 newline;
        }
    }
}

int32_t main() {
    IOS;

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
