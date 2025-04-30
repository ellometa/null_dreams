// ============================================================================ //
// ||                                                                        || //
// ||                                                                        || //
//*||                     // Jigyasu's Template for cpp //                   || //
// ||--------------------------Expert till July 2025-------------------------|| //
// ||                                                                        || //
// ||                                                                        || //
// ============================================================================ //

#include <bits/stdc++.h>
using namespace std;

#define fast_io cin.sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long int
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) (int)(x).size()
#define f first
#define s second
#define MOD 1000000007
#define endl "\n"
#define IN(a, n) vi a(n); fr(i, 0, n) cin >> a[i];
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

#define vi vector<int>

#define fr(i, a, b) for (int i = a; i < b; i++)
#define frr(i, a, b) for (int i = a; i > b; i--)

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

//?--------------------------------------------------------------------------------------------------------------------

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

//?--------------------------------------------------------------------------------------------------------------------

//* Modular Multiplication
ll mod_mul(ll a, ll b) {return ((a % MOD) * (b % MOD)) % MOD;}

//* Binary Exponentiation
ll binpow(ll a, ll b, ll m = MOD) {
    ll res = 1;
    a %= m;
    while (b) {
        if (b & 1ll) res = res * a % m;
        a = mod_mul(a, a);
        b >>= 1ll;
    }
    return res;
}

//* Modular Addition
ll mod_add(ll a, ll b) {return ((a % MOD) + (b % MOD)) % MOD;}

//* Modular Subtraction
ll mod_sub(ll a, ll b) {return ((a % MOD) - (b % MOD) + MOD) % MOD;}

//* Modular Division (using Modular Inverse)
ll mod_inv(ll a, ll m = MOD) {return binpow(a, m - 2, m);}  // Fermat's Little Theorem

ll mod_div(ll a, ll b) {return mod_mul(a, mod_inv(b));}

//?--------------------------------------------------------------------------------------------------------------------

//! Factorial with modular arithmetic
vector<long long> fact, inv_fact;
void init_factorial(int n, ll m = MOD) {
    fact.resize(n + 1, 1);
    inv_fact.resize(n + 1, 1);
    for (int i = 2; i <= n; ++i) fact[i] = fact[i - 1] * i % m;
    inv_fact[n] = binpow(fact[n], m - 2, m); // Fermat's Little Theorem for modular inverse
    for (int i = n - 1; i >= 1; --i) inv_fact[i] = inv_fact[i + 1] * (i + 1) % m;
}
long long nCr(int n, int r, ll m = MOD) {
    if (r > n) return 0;
    return fact[n] * inv_fact[r] % m * inv_fact[n - r] % m;
}

//?--------------------------------------------------------------------------------------------------------------------
//?--------------------------------------------------------------------------------------------------------------------

// vi primes;

void Solve() {
    int n; cin >> n;
    IN(vec, n);
    vi ans;
    ans.pb(0);
    for (int i = 1; i < n; i++) {
        bitset<32>temp1(ans.back() ^ vec[i-1]);
        bitset<32>temp2(vec[i]);
        string temp = "";
        for (int i = 31; i >= 0; i--) {
            if (!temp2[i] && temp1[i]) temp += "1";
            else temp += "0";
        }
        // reverse(all(temp));
        // cout << temp1 << endl;
        // cout << temp2 << endl;
        // cout << temp << endl;
        int hi = stoll(temp, 0, 2);
        ans.pb(hi);
    }
    print(ans);
}

int32_t main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    // primes = sieve(1e7);

    fast_io;

    int t = 1;
    cin >> t;
    while (t--) Solve();
}