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

//.........Bit_Manipulation...........//
#define msb(mask) (63-__builtin_clzll(mask))  /// 0 -> -1
#define lsb(mask) __builtin_ctzll(mask)  /// 0 -> 64
#define lusb(mask) __builtin_ctzll(~(mask))
#define cntsetbit(mask) __builtin_popcountll(mask)
#define checkbit(mask,bit) ((mask >> bit) & 1ll)
#define onbit(mask,bit) ((mask)|(1LL<<(bit)))
#define offbit(mask,bit) ((mask)&~(1LL<<(bit)))
#define changebit(mask,bit) ((mask)^(1LL<<bit))

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


int sum_digits(long long x) {
    int s = 0;
    while (x > 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

const int INF = LLONG_MAX >> 1;

//?-----------------------------------------------------------------------------------------------------------

void solve(){
    in(n);
    
}

signed main(){
    fast_input();

    int t=1;
    // cin >> t;
    for (int i = 1; i <= t; i++){
        // cout << "Case " << i << ":" << endl;
        solve();
    }

    return 0;
}