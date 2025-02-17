#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

const int maxn = 1e6+1;

vector<bool> is_prime(maxn, 1);

void sieve()
{
    is_prime[0] = 0;
    is_prime[1] = 0;
    for (int i = 2; i * i <= maxn ; ++i)
    {
        if(is_prime[i] == 1)
        {
            for(int u = i * i ; u < maxn ; u += i)
            {
                is_prime[u] = 0; 
            }
        }
    }
}


int divisors[maxn];

void divs()
{
    for (int i = 1; i <= maxn; ++i)
        for (int j = i; j <= maxn; j += i)
            ++divisors[j];
}


int count_prime_divs[maxn];

void prep(){
    for(int i = 1; i <= maxn; i++){
        count_prime_divs[i] = count_prime_divs[i - 1] + is_prime[divisors[i]];
    }
}

void solve() {

    
    
    int a, b; cin >> a >> b;

    
    cout << count_prime_divs[b] - count_prime_divs[a-1] newline;
    // cout << count newline;
    
    // cout << is_prime[divisors[]];

}

int32_t main() {
    IOS;
    sieve();
    divs();
    prep();
    
    int t=1;
    cin >> t;    
    while (t--) {
        solve();
    }

    return 0;
}