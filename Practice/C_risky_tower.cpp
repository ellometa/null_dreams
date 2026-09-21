
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
void solve() {
    ll n, m;
    cin >> n >> m;

    vi v(n);
    ina(v, n);

    vector<int> g(n * m);
    fr(i, 0, n * m)
        cin >> g[i];

    // emptying any row always works and costs exactly m
    ll ans = m;

    // top: the largest `ans` values among rows k..n, descending
    static vector<int> top, buf, merged;
    top.clear();

    frr(k, n - 1, -1) {
        ll keep = ans;

        buf.assign(g.begin() + k * m, g.begin() + (k + 1) * m);
        if ((ll)buf.size() > keep) {
            partial_sort(buf.begin(), buf.begin() + keep, buf.end(), greater<int>());
            buf.resize(keep);
        } else {
            sort(all(buf), greater<int>());
        }

        merged.resize(top.size() + buf.size());
        merge(all(top), all(buf), merged.begin(), greater<int>());
        if ((ll)merged.size() > keep)
            merged.resize(keep);
        top.swap(merged);

        // fewest of the largest suffix values summing to >= v[k]
        ll sum = 0;
        fr(c, 0, sz(top)) {
            sum += top[c];
            if (sum >= v[k]) {
                ans = min(ans, c + 1);
                break;
            }
        }
        if ((ll)top.size() > ans)
            top.resize(ans);
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
