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
    in(n);
    vi nums(n);
    ina(nums, n);

    if (n == 1) {
        cout << 0 nline;
        return;
    }
    ll max1 = nums[n - 1] - *min_element(nums.begin(), nums.end() - 1);
    ll max2 = (*max_element(nums.begin() + 1, nums.end())) - (nums[0]);

    ll max3 = 0;
    fr(i, 0, n - 1) {
        max3 = max(max3, (nums[i] - nums[i + 1]));
    }
    max3 = max(max3, (nums[n - 1] - nums[0]));

    cout << max(max1, max(max2, max3)) nline;
}

int main() {
    fast_input();

    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ":" << endl;
        solve();
    }

    return 0;
}
