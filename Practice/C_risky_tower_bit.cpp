
#include <bits/stdc++.h>

#define AKY AayushKYadav ^ _ ^

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define fast_input()             \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define fr(i, a, b) for (ll i = (a); i < (ll)(b); ++i)   // for loop exclusive
#define fri(i, a, b) for (ll i = (a); i <= (ll)(b); ++i) // for loop inclusive
#define frr(i, a, b) for (ll i = (a); i > (ll)(b); --i)  // for loop reverse
#define in(n) \
    ll n;     \
    cin >> n;
#define ina(x, n)              \
    for (ll i = 0; i < n; ++i) \
        cin >> x[i];
#define input_set(set, n)        \
    for (ll i = 0; i < n; i++) { \
        ll x;                    \
        cin >> x;                \
        set.insert(x);           \
    }

#define pb push_back
#define vi vector<ll>
#define mii map<ll, ll>
#define vvi vector<vector<ll>>
#define vpi vector<pair<ll, ll>>
#define pi pair<ll, ll>
#define si set<ll>

#define ff first
#define ss second
constexpr ll MOD = 1e9 + 7;
#define endl "\n"
#define oyes cout << "YES" << endl;
#define ono cout << "NO" << endl;
#define oyess cout << "Yes" << endl;
#define onoo cout << "No" << endl;
#define ve1 cout << "-1" << endl;

#define all(x) (x).begin(), (x).end()
#define rall(x) reverse((x).begin(), (x).end())
#define sz(x) (ll)(x).size()

#define nline << '\n'

//?-----------------------------------------------------------------------------------------------------------
// Offline: sort every piece by damage descending once, give it a slot.
// Sweep rows bottom-up, "activating" each row's pieces in a Fenwick tree.
// f(k) = binary-lifting descent for the shortest active prefix with sum >= v[k].
void solve() {
    ll n, m;
    cin >> n >> m;

    vi v(n);
    ina(v, n);

    ll N = n * m;
    vector<int> g(N);
    for (int &x : g)
        cin >> x;

    // pack (value, index) so one sort gives descending damage order
    vector<ll> key(N);
    fr(i, 0, N)
        key[i] = ((ll)g[i] << 20) | i;
    sort(all(key), greater<ll>());

    vector<int> slot(N); // slot[i] = 1-based rank of piece i in descending order
    fr(r, 0, N)
        slot[key[r] & ((1 << 20) - 1)] = r + 1;

    vector<int> bitCnt(N + 1, 0);
    vector<ll> bitSum(N + 1, 0);
    auto add = [&](ll i, ll val) {
        for (; i <= N; i += i & -i) {
            bitCnt[i] += 1;
            bitSum[i] += val;
        }
    };

    ll LOG = 1;
    while ((LOG << 1) <= N)
        LOG <<= 1;

    ll ans = m;
    frr(k, n - 1, -1) {
        fr(j, 0, m)
            add(slot[k * m + j], g[k * m + j]);

        // largest prefix whose active sum is still < v[k]
        ll pos = 0, curSum = 0, curCnt = 0;
        for (ll pw = LOG; pw; pw >>= 1) {
            if (pos + pw <= N && curSum + bitSum[pos + pw] < v[k]) {
                pos += pw;
                curSum += bitSum[pos];
                curCnt += bitCnt[pos];
            }
        }
        if (pos < N)                     // one more active piece tips it over
            ans = min(ans, curCnt + 1);
    }

    cout << ans nline;
}

int main() {
    fast_input();

    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}
