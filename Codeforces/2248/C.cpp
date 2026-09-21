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
#define fr(i, a, b) for (ll i = (a); i < (ll)(b); ++i)
#define fri(i, a, b) for (ll i = (a); i <= (ll)(b); ++i)
#define frr(i, a, b) for (ll i = (a); i > (ll)(b); --i)
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

struct slot {
    ll l, r, w;
};

void solve() {
    in(n);
    vi a(2 * n);
    ina(a, 2 * n);

    vi Lwala(n + 1, -1), Rwala(n + 1, -1);

    fr(i, 0, 2 * n) {
        if (Lwala[a[i]] == -1)
            Lwala[a[i]] = i;
        else
            Rwala[a[i]] = i;
    }

    vector<slot> slots;

    fri(i, 1, n) {
        ll len = Rwala[i] - Lwala[i] + 1;
        slots.pb({Lwala[i], Rwala[i], len * (len - 1)});
    }

    sort(all(slots), [](const slot &a, const slot &b) {
        return a.r < b.r;
    });

    vi rights;
    for (auto &x : slots)
        rights.pb(x.r);
    
    vi dp(n + 1);

    fri(i, 1, n) {
        dp[i] = dp[i - 1];
        ll l = slots[i - 1].l;
        ll w = slots[i - 1].w;
        ll j = lower_bound(all(rights), l) - rights.begin();
        dp[i] = max(dp[i], dp[j] + w);
    }

    cout << 2 * n + dp[n] << endl;
}

int main() {
    fast_input();

    ll t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}