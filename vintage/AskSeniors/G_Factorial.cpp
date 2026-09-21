#include <bits/stdc++.h>
using namespace std;

#define fast_input() ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define pb push_back
#define nline <<'\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) (int)(x).size()
#define f first
#define s second
#define MOD 1000000007
#define nline <<"\n"

#define vi vector<int>

#define fr(i, a, b) for (int i = a; i < b; i++)
#define frr(i, a, b) for (int i = a; i > b; i--)

#define IN(a, n) vi a(n); fr(i, 0, n) cin >> a[i];

const int INF = LLONG_MAX >> 1;

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


//?-----------------------------------------------------------------------------------------------------------

void solve(){
    int n = 21;

    vi fact(n, 1);

    for (int i = 1; i < 21; i++){
        fact[i]=fact[i-1]*i;
        // cout << i << " " << fact[i-1] nline;
    }

    // print(fact);
    int x; cin >> x;
    cout << fact[x] nline;
    
    
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



//*     EmasculatorJi's Template//
//*     Last year to achieve my goals, pray_emoji