#include <bits/stdc++.h>
#include <atcoder/lazysegtree>

#define AKY AayushKYadav ^ _ ^

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace atcoder;

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
constexpr ll INF = LLONG_MAX >> 1;


//?----------------------------------------------------------------------------------------------------------

ll seg_max(ll a, ll b) {
    return max(a, b);
}

ll seg_identity() {
    return -INF;
}

ll seg_apply(ll lazy, ll value) {
    return lazy + value;
}

ll seg_compose(ll outer, ll inner) {
    return outer + inner;
}

ll seg_no_op() {
    return 0;
}

using Seg = lazy_segtree<ll, seg_max, seg_identity, ll, seg_apply, seg_compose, seg_no_op>;

void solve() {
    in(n);
    in(k);

    vector<ll> pitch(n + 1), weight(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> pitch[i];
    }
    for (ll i = 1; i <= n; ++i) {
        cin >> weight[i];
    }

    vector<ll> sorted_pitches(pitch.begin() + 1, pitch.end());
    sort(all(sorted_pitches));
    for (ll i = 1; i <= n; ++i) {
        pitch[i] = lower_bound(all(sorted_pitches), pitch[i]) - sorted_pitches.begin();
    }

    vector<ll> best(n + 1, -INF), next_best(n + 1, -INF);
    best[0] = 0;

    for (ll movement = 1; movement <= k; ++movement) {
        Seg seg(n);

        vector<ll> last_seen(n, 0), second_last_seen(n, 0);

        for (ll i = 1; i <= n; ++i) {
            seg.set(i - 1, best[i - 1]);

            ll p = pitch[i];
            ll last = last_seen[p];
            ll second_last = second_last_seen[p];

            seg.apply(last, i, weight[i]);

            if (last > 0) {
                seg.apply(second_last, last, -weight[last]);
            }

            second_last_seen[p] = last;
            last_seen[p] = i;

            next_best[i] = seg.all_prod();
        }

        swap(best, next_best);
    }

    cout << best[n] << endl;
}

int main() {
    fast_input();

    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ":" << endl;
        solve();
    }

    return 0;
}