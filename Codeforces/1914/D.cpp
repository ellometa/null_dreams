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
    in(numDays);
    // friends[activity][day]: activity 0 = skiing, 1 = movie, 2 = board games
    vvi friends(3, vi(numDays));
    fr(activity, 0, 3) ina(friends[activity], numDays);

    // bestTotal[mask] = max friends when the activities in `mask` are each
    // assigned to a distinct day. Bit b set => activity b is assigned.
    vi bestTotal(8, -1);
    bestTotal[0] = 0;

    fr(day, 0, numDays) {
        // Copy first so this day can fill at most one activity slot this round.
        vi nextBest = bestTotal;
        fr(mask, 0, 8) {
            if (bestTotal[mask] < 0)
                continue; // unreachable state
            fr(activity, 0, 3) {
                if (mask & (1 << activity))
                    continue; // this activity already assigned
                ll newMask = mask | (1 << activity);
                nextBest[newMask] = max(nextBest[newMask],
                                        bestTotal[mask] + friends[activity][day]);
            }
        }
        bestTotal = nextBest;
    }

    // mask 7 (0b111) => all three activities assigned on distinct days
    cout << bestTotal[7] nline;
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
