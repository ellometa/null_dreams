#include <bits/stdc++.h>

#define AKY AayushKYadav ^_^

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define fast_input() ios::sync_with_stdio(false); cin.tie(nullptr);
#define fr(i, a, b) for (ll i = (a); i < (ll)(b); ++i)   // for loop exclusive
#define fri(i, a, b) for (ll i = (a); i <= (ll)(b); ++i) // for loop inclusive
#define frr(i, a, b) for (ll i = (a); i > (ll)(b); --i)  // for loop reverse
#define in(n)    \
    ll n; cin >> n;
#define ina(x, n)               \
    for (ll i = 0; i < n; ++i) \
        cin >> x[i];
#define input_set(set, n)       \
    for(ll i=0;i<n;i++){ll x;cin>>x;set.insert(x);}

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


#define nline <<'\n'

//?-----------------------------------------------------------------------------------------------------------

void solve(){
    in(n);
    in(m);

    vi v(n);
    ina(v, n);

    // int keeps the grid at 4MB instead of 8MB; a_ij <= 1e9 fits fine
    vector<int> g(n * m);
    for (int &x : g)
        cin >> x;

    // emptying any row always collapses the tower, and costs exactly m
    ll ans = m;

    // min-heap holding the `ans` largest pieces of rows k..n, S = their sum
    priority_queue<int, vector<int>, greater<int>> pq;
    ll S = 0;

    frr(k, n - 1, -1) {
        // activate row k
        fr(j, 0, m) {
            int x = g[k * m + j];
            pq.push(x);
            S += x;
            if (sz(pq) > ans) { // never need more than `ans` pieces
                S -= pq.top();
                pq.pop();
            }
        }

        // row k is damaged only by removals in rows k..n
        if (S >= v[k]) {
            while (S - pq.top() >= v[k]) { // peel off the useless smallest
                S -= pq.top();
                pq.pop();
            }
            ans = sz(pq); // == f(k), and f(k) < old ans
        }
    }

    cout << ans nline;
}

int main(){
    fast_input();

    ll t=1;
    cin >> t;
    for (ll i = 1; i <= t; i++){
        // cout << "Case " << i << ":" << endl;
        solve();
    }

    return 0;
}
