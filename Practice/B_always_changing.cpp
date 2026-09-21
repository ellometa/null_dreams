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
    string s;
    cin >> s;

    ll totalZeros = count(all(s), '0');
    ll totalOnes = n - totalZeros;

    // whatever we keep, we delete (totalZeros - keptZeros) zeros and
    // (totalOnes - keptOnes) ones, and those two counts must stay within 1
    ll originalImbalance = totalZeros - totalOnes;

    // collapse runs: this is the longest alternating subsequence of s
    string compressed;
    for (char ch : s)
        if (compressed.empty() || compressed.back() != ch)
            compressed.pb(ch);
    ll compressedLen = sz(compressed);

    ll bestKeptLen = -1;

    // any alternating kept string has (#zeros - #ones) equal to -1, 0 or +1
    fri(keptBalance, -1, 1) {
        ll deletionGap = originalImbalance - keptBalance;
        if (abs(deletionGap) > 1) // the deletions could not alternate
            continue;

        ll keptLen;
        if (keptBalance == 0) {
            // balanced means even length, so trim one char if needed
            keptLen = compressedLen - (compressedLen % 2);
        } else {
            char neededFirstChar = (keptBalance == 1) ? '0' : '1';
            size_t startIdx = compressed.find(neededFirstChar);
            if (startIdx == string::npos)
                continue; // that character is not present at all

            keptLen = compressedLen - (ll)startIdx; // stretch to the end
            if (keptLen % 2 == 0)                   // odd length carries the +-1
                keptLen--;
        }

        bestKeptLen = max(bestKeptLen, keptLen);
    }

    if (bestKeptLen < 0) {
        ve1
    } else {
        cout << n - bestKeptLen nline;
    }
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
