//                           _._
//                         _/:|:
//                        /||||||.
//                        ||||||||.
//                       /|||||||||:
//                      /|||||||||||
//                     .|||||||||||||
//                     | ||||||||||||:
//                   _/| |||||||||||||:_=---.._
//                   | | |||||:'''':||  '~-._  '-.
//                 _/| | ||'         '-._   _:    ;
//                 | | | '               '~~     _;
//                 | '                _.=._    _-~
//              _.~                  {     '-_'
//      _.--=.-~       _.._          {_       }
//  _.-~   @-,        {    '-._     _. '~==+  |
// ('          }       \_      \_.=~       |  |
// `======='  /_         ~-_    )         <_oo_>
//   `-----~~/ /'===...===' +   /
//          <_oo_>         /  //
//                        /  // 
//                       <_oo_>




//EmasculatorJi's Template//
// Last year to achieve my goals, pray_emoji


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
#define endl "\n"

#define vi vector<int>

#define fr(i, a, b) for (int i = a; i < b; i++)
#define frr(i, a, b) for (int i = a; i > b; i--)

#define IN(a, n) vi a(n); fr(i, 0, n) cin >> a[i];

//?--------------------------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------------------------

const int INF = LLONG_MAX >> 1;

//--------------------------------------------------------------------------------------------------------------------

//* GCD using the Euclidean Algorithm
template <typename T>
T gcd(T a, T b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

//* LCM using the GCD formula
template <typename T>
T lcm(T a, T b) {return (a / gcd(a, b)) * b;}  // a * b / gcd(a, b)

//* Sieve of Eratosthenes for primes
vector<int> sieve(int n) {
    vi st;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        if (is_prime[i]) {
            st.pb(i);
        }
    }
    return st;
}

//---------------------------------------------------------------------------------------------------------

//* Modular Multiplication
int mod_mul(int a, int b) {return ((a % MOD) * (b % MOD)) % MOD;}

//* Binary Exponentiation
int binpow(int a, int b, int m = MOD) {
    int res = 1;
    a %= m;
    while (b) {
        if (b & 1LL) res = res * a % m;
        a = mod_mul(a, a);
        b >>= 1LL;
    }
    return res;
}
 
//* Modular Addition
int mod_add(int a, int b) {return ((a % MOD) + (b % MOD)) % MOD;}
 
//* Modular Subtraction
int mod_sub(int a, int b) {return ((a % MOD) - (b % MOD) + MOD) % MOD;}
 
//* Modular Division (using Modular Inverse)
int mod_inv(int a, int m = MOD) {return binpow(a, m - 2, m);}  // Fermat's Little Theorem
 
int mod_div(int a, int b) {return mod_mul(a, mod_inv(b));}
 
//?----------------------------------------------------------------------------------------------------------

//! Factorial with modular arithmetic
vector<int> fact, inv_fact;
void init_factorial(int n, int m = MOD) {
    fact.resize(n + 1, 1);
    inv_fact.resize(n + 1, 1);
    for (int i = 2; i <= n; ++i) fact[i] = fact[i - 1] * i % m;
    inv_fact[n] = binpow(fact[n], m - 2, m); // Fermat's Little Theorem for modular inverse
    for (int i = n - 1; i >= 1; --i) inv_fact[i] = inv_fact[i + 1] * (i + 1) % m;
}
int nCr(int n, int r, int m = MOD) {
    if (r > n) return 0;
    return fact[n] * inv_fact[r] % m * inv_fact[n - r] % m;
}

//?-----------------------------------------------------------------------------------------------------------

void Solve(){
    int n; cin >> n;
    cout << n+1;
    
}

signed main(){
    fast_input();

    int t=1;
    // cin >> t;
    for (int i = 1; i <= t; i++){
        // cout << "Case " << i << ":" << endl;
        Solve();
    }

    return 0;
}
