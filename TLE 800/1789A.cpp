#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define fast_input() ios::sync_with_stdio(false); cin.tie(nullptr);

#define int long long
#define fr(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define frr(i, a, b) for (int i = (a); i > (int)(b); --i)
#define in(n)    \
    long long n; cin >> n;
#define ina(x, n)               \
    for (int i = 0; i < n; ++i) \
        cin >> x[i];
#define input_set(set, n)       \
    for(int i=0;i<n;i++){int x;cin>>x;set.insert(x);}
#define double long double
#define pb push_back
#define vi vector<int>
#define mii map<int, int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define si set<int>

#define ff first
#define ss second
#define MOD 1000000007
#define endl "\n"
#define oyes cout << "YES" << endl;
#define ono cout << "NO" << endl;
#define oyess cout << "Yes" << endl;
#define onoo cout << "No" << endl;
#define ve1 cout << "-1" << endl;

#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define rall(x) reverse((x).begin(), (x).end())
#define sz(x) (int)(x).size()

#define nline <<'\n'

const int INF = LLONG_MAX >> 1;

//?-----------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------------------

//* Debuggers
#define debug(x) cout << #x << " = " << x << endl;


template<typename T>
void print_container(const T& container) {
    for (auto it = container.begin(); it != container.end(); ++it) {
        cout << *it;
        if (next(it) != container.end()) cout << " ";
    }
    cout << endl;
}
#define print(x) print_container(x);

void solve(){
    in(n);
    vi nums(n);
    ina(nums, n);

    sort(all(nums));
    // cout << __gcd(nums[1],nums[0]) nline;
    bool flag = false;

    fr(i, 0, n){
        fr(j, 0, n){
            if(i!=j){
                if (__gcd(nums[i], nums[j]) <=2){
                    flag = true;
                    // oyess;
                    break;
                }
            }
        }
    }

    if(flag){
        oyess;
    }else{
        onoo;
    }
    // all i need is two coprime numbers
}

signed main(){
    fast_input();

    int t=1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        // cout << "Case " << i << ":" << endl;
        solve();
    }

    return 0;
}