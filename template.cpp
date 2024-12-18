#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^ 

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

bool isPrime(int n){
    if (n<2) return false;
    for (int i = 2; i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}


vector<int> is_prime;
void sieve(int n)
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
}

long long binpowmod(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

void solve() {

    int n; cin >> n;
    vector<int> vecarr(n);
    for(auto &x:vecarr){cin>> x;}    

}

int32_t main() {
    IOS;

    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
//practice like you never win