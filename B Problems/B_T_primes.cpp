#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;



int n = 1000001;  
vector<long long> squareprimes;
vector<long long> is_prime(n, 1);

void sieve()
{
    is_prime[0] = 0;
    is_prime[1] = 0;
    for (int i = 2; i * i <= n ; ++i)
    {
        if(is_prime[i] == 1)
        {
            for(int u = i * i ; u < n ; u += i)
            {
                is_prime[u] = 0; 
            }
        }
    }
    for (int i = 2; i < n; ++i)
    {
        if(is_prime[i] == 1) squareprimes.push_back(i * i);
    }
}

void solve(){

    int x; cin >> x;
    vector<long long> v(x); 
    
    for(auto &i : v) cin >> i;


    for (int i = 0; i < x; i++){
        if (binary_search(all(squareprimes), v[i])){
            cout << "YES" newline;
        }
        else{
            cout << "NO" newline;
        }
    }
    
}

int32_t main() {
    IOS;
    sieve();

    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}