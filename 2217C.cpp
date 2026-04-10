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

//.........Bit_Manipulation...........//
#define msb(mask) (63 - __builtin_clzll(mask)) /// 0 -> -1
#define lsb(mask) __builtin_ctzll(mask)        /// 0 -> 64
#define lusb(mask) __builtin_ctzll(~(mask))
#define cntsetbit(mask) __builtin_popcountll(mask)
#define checkbit(mask, bit) ((mask >> bit) & 1ll)
#define onbit(mask, bit) ((mask) | (1LL << (bit)))
#define offbit(mask, bit) ((mask) & ~(1LL << (bit)))
#define changebit(mask, bit) ((mask) ^ (1LL << bit))

constexpr ll INF = LLONG_MAX >> 1;

//---------------------------------------------------------------------------------------------------------

//* Modular Multiplication
ll mod_mul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

//* Binary Exponentiation
ll binpow(ll a, ll b, ll m = MOD) {
    ll res = 1;
    a %= m;
    while (b) {
        if (b & 1LL)
            res = res * a % m;
        a = mod_mul(a, a);
        b >>= 1LL;
    }
    return res;
}

//* Modular Addition
ll mod_add(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

//* Modular Subtraction
ll mod_sub(ll a, ll b) {
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

//* Modular Division (using Modular Inverse)
ll mod_inv(ll a, ll m = MOD) {
    return binpow(a, m - 2, m);
} // Fermat's Little Theorem

ll mod_div(ll a, ll b) {
    return mod_mul(a, mod_inv(b));
}

//?----------------------------------------------------------------------------------------------------------

// Factorial with modular arithmetic
vector<ll> fact, inv_fact;
void init_factorial(ll n, ll m = MOD) {
    fact.resize(n + 1, 1);
    inv_fact.resize(n + 1, 1);
    for (ll i = 2; i <= n; ++i)
        fact[i] = fact[i - 1] * i % m;
    inv_fact[n] = binpow(fact[n], m - 2, m); // Fermat's Little Theorem for modular inverse
    for (ll i = n - 1; i >= 1; --i)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % m;
}
ll nCr(ll n, ll r, ll m = MOD) {
    if (r > n)
        return 0;
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
T lcm(T a, T b) {
    return (a / gcd(a, b)) * b;
} // a * b / gcd(a, b)

//* Sieve of Eratosthenes for primes
vi sieve(ll n) {
    vi st;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (ll i = 0; i <= n; i++) {
        if (is_prime[i]) {
            st.pb(i);
        }
    }
    return st;
}

//* Debuggers
#define debug(x) cout << #x << " = " << x << endl;

template <typename T>
void print_container(const T &container) {
    for (auto it = container.begin(); it != container.end(); ++it) {
        cout << *it;
        if (next(it) != container.end())
            cout << " ";
    }
    cout << endl;
}
#define print(x) print_container(x);

//?-----------------------------------------------------------------------------------------------------------

void solve() {
    in(n);
    vi nums(n);
    ina(nums, n);
    sort(all(nums));

    print(nums);
}

int main() {
    fast_input();

    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ":" << endl;
        solve();
    }

    return 0;
}
