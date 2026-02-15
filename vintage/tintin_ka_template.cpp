#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<long long>;
const int MOD = 1000000007;
const int inf = 1e9;
const int N = 100005;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using ld = long double;
using vld = vector<long double>;
using dd = double;
using vd = vector<double>;
#define pb push_back
#define I(x)          \
    for (auto &i : x) \
    cin >> i
const long long mod = 998244353;
const ll INF = 1e18;
// ------------------------- number Theory ------------------------- //
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

ll modExp(ll bn, ll exp, ll mod = MOD)
{
    ll result = 1;
    bn %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * bn) % mod;
        bn = (bn * bn) % mod;
        exp >>= 1;
    }
    return result;
}

ll extendedGCD(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll g = extendedGCD(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
}

ll modInverse(ll a, ll mod = MOD)
{
    ll x, y;
    ll g = extendedGCD(a, mod, x, y);
    if (g != 1)
        return -1; // Inverse doesn't exist if a &  mod are not coprime.
    return (x % mod + mod) % mod;
}

vector<int> sieve(int n)
{
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            for (int j = 2 * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return primes;
}

vector<pair<ll, int>> primeFactorization(ll n)
{
    vector<pair<ll, int>> factors;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                count++;
                n /= i;
            }
            factors.push_back({i, count});
        }
    }
    if (n > 1)
        factors.push_back({n, 1});
    return factors;
}

ll phi(ll n)
{
    ll result = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

// ------------------------- Matrix Exponentiation ------------------------- //
//------------------------------------------------------------------------- //
using Matrix = vector<vector<ll>>;

Matrix multiplyMatrix(const Matrix &A, const Matrix &B, ll mod = MOD)
{
    int n = A.size(), m = B[0].size(), p = A[0].size();
    Matrix C(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < p; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}

Matrix matrixPower(Matrix A, ll power, ll mod = MOD)
{
    int n = A.size();
    Matrix result(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
        result[i][i] = 1;
    while (power > 0)
    {
        if (power & 1)
            result = multiplyMatrix(result, A, mod);
        A = multiplyMatrix(A, A, mod);
        power >>= 1;
    }
    return result;
}

// ------------------------- Combinatorics ------------------------- //
//-----------------------------------------------------------------//
vector<ll> fact, invFact;
void initFactorials(int n, ll mod = MOD)
{
    fact.resize(n + 1);
    invFact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    invFact[n] = modInverse(fact[n], mod);
    for (int i = n - 1; i >= 0; i--)
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
}

ll nCr(int n, int r, ll mod = MOD)
{
    if (r < 0 || r > n)
        return 0;
    return ((fact[n] * invFact[r]) % mod * invFact[n - r]) % mod;
}

// ------------------------- Data Structures ------------------------- //
//-------------------------------------------------------------------- //

// Fenwick Tree (Binary Indexed Tree)
struct FenwickTree
{
    int n;
    vector<ll> fenw;
    FenwickTree(int n) : n(n) { fenw.assign(n + 1, 0); }
    void update(int i, ll delta)
    {
        for (; i <= n; i += i & -i)
            fenw[i] += delta;
    }
    ll query(int i)
    {
        ll sum = 0;
        for (; i > 0; i -= i & -i)
            sum += fenw[i];
        return sum;
    }
    ll rangeQuery(int l, int r) { return query(r) - query(l - 1); }
};

// Generic Segment Tree
template <typename T>
struct SegmentTree
{
    int n;
    vector<T> tree;
    function<T(T, T)> combine;
    T defaultValue;

    SegmentTree(vector<T> &arr, function<T(T, T)> combine, T defaultValue)
        : combine(combine), defaultValue(defaultValue)
    {
        n = arr.size();
        tree.resize(4 * n, defaultValue);
        build(arr, 0, 0, n - 1);
    }

    void build(vector<T> &arr, int idx, int l, int r)
    {
        if (l == r)
        {
            tree[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2 * idx + 1, l, mid);
        build(arr, 2 * idx + 2, mid + 1, r);
        tree[idx] = combine(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    void update(int pos, T val, int idx, int l, int r)
    {
        if (l == r)
        {
            tree[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(pos, val, 2 * idx + 1, l, mid);
        else
            update(pos, val, 2 * idx + 2, mid + 1, r);
        tree[idx] = combine(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    T query(int ql, int qr, int idx, int l, int r)
    {
        if (ql > r || qr < l)
            return defaultValue;
        if (ql <= l && r <= qr)
            return tree[idx];
        int mid = (l + r) / 2;
        return combine(query(ql, qr, 2 * idx + 1, l, mid),
                       query(ql, qr, 2 * idx + 2, mid + 1, r));
    }

    void update(int pos, T val) { update(pos, val, 0, 0, n - 1); }
    T query(int l, int r) { return query(l, r, 0, 0, n - 1); }
};

// Disjoint Set Union (DSU)

struct DSU
{
    vector<int> Pi, rank;
    DSU(int n)
    {
        Pi.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            Pi[i] = i;
    }
    int find(int a) { return Pi[a] == a ? a : Pi[a] = find(Pi[a]); }
    void unionSet(int a, int b)
    {
        a = find(a), b = find(b);
        if (a == b)
            return;
        if (rank[a] < rank[b])
            swap(a, b);
        Pi[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
};

// Trie for String Operations (supports lowercase letters)
struct TrieNode
{
    bool isEnd;
    array<TrieNode *, 26> children;
    TrieNode() : isEnd(false) { children.fill(nullptr); }
};

struct Trie
{
    TrieNode *root;
    Trie() { root = new TrieNode(); }

    // Insert a word into the Trie.
    void insert(const string &word)
    {
        TrieNode *cur = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (!cur->children[idx])
                cur->children[idx] = new TrieNode();
            cur = cur->children[idx];
        }
        cur->isEnd = true;
    }

    // Search for a word in the Trie.
    bool search(const string &word)
    {
        TrieNode *cur = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (!cur->children[idx])
                return false;
            cur = cur->children[idx];
        }
        return cur && cur->isEnd;
    }

    // Check if any word in the Trie starts with the gtempen prefix.
    bool startsWith(const string &prefix)
    {
        TrieNode *cur = root;
        for (char ch : prefix)
        {
            int idx = ch - 'a';
            if (!cur->children[idx])
                return false;
            cur = cur->children[idx];
        }
        return true;
    }
};

// Sparse Table for Range Minimum Query (RMQ)
struct SparseTable
{
    int n;
    vector<vector<int>> st;
    vector<int> logVal;

    SparseTable(const vector<int> &arr)
    {
        n = arr.size();
        logVal.resize(n + 1);
        for (int i = 2; i <= n; i++)
            logVal[i] = logVal[i / 2] + 1;
        int k = logVal[n] + 1;
        st.assign(n, vector<int>(k));
        for (int i = 0; i < n; i++)
            st[i][0] = arr[i];
        for (int j = 1; j < k; j++)
        {
            for (int i = 0; i + (1 << j) <= n; i++)
            {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    // Returns the minimum value in [L, R].
    int query(int L, int R)
    {
        int j = logVal[R - L + 1];
        return min(st[L][j], st[R - (1 << j) + 1][j]);
    }
};

// Ordered Set using GNU PBDS (requires g++ extensions)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using OrderedSet = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// ------------------------- Graph Algorithms ------------------------- //
namespace Graph
{
    vector<int> bfs(int src, const vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int nxt : adj[cur])
                if (dist[nxt] == -1)
                {
                    dist[nxt] = dist[cur] + 1;
                    q.push(nxt);
                }
        }
        return dist;
    }

    void dfsUtil(int v, const vector<vector<int>> &adj, vector<bool> &wineited)
    {
        wineited[v] = true;
        for (int nxt : adj[v])
            if (!wineited[nxt])
                dfsUtil(nxt, adj, wineited);
    }

    vector<ll> dijkstra(int src, const vector<vector<pair<int, ll>>> &adj)
    {
        int n = adj.size();
        vector<ll> dist(n, LLONG_MAX);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dist[u])
                continue;
            for (auto &edge : adj[u])
            {
                int v = edge.first;
                ll w = edge.second;
                if (dist[u] != LLONG_MAX && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    vector<int> topologicalSort(const vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> indegree(n, 0);
        for (int u = 0; u < n; u++)
            for (int v : adj[u])
                indegree[v]++;
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);
        vector<int> order;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (int v : adj[u])
                if (--indegree[v] == 0)
                    q.push(v);
        }
        if (order.size() != n)
            order.clear(); // Cycle detected.
        return order;
    }

    void topoSortDFSUtil(int v, const vector<vector<int>> &adj, vector<bool> &wineited, stack<int> &st)
    {
        wineited[v] = true;
        for (int nxt : adj[v])
            if (!wineited[nxt])
                topoSortDFSUtil(nxt, adj, wineited, st);
        st.push(v);
    }

    vector<int> topoSortDFS(const vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<bool> wineited(n, false);
        stack<int> st;
        for (int i = 0; i < n; i++)
            if (!wineited[i])
                topoSortDFSUtil(i, adj, wineited, st);
        vector<int> order;
        while (!st.empty())
        {
            order.push_back(st.top());
            st.pop();
        }
        return order;
    }

    vector<ll> bellmanFord(int n, int src, const vector<tuple<int, int, ll>> &edges)
    {
        vector<ll> dist(n, LLONG_MAX);
        dist[src] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (auto &edge : edges)
            {
                int u, v;
                ll w;
                tie(u, v, w) = edge;
                if (dist[u] != LLONG_MAX && dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }
        // Check for negattempe cycles.
        for (auto &edge : edges)
        {
            int u, v;
            ll w;
            tie(u, v, w) = edge;
            if (dist[u] != LLONG_MAX && dist[u] + w < dist[v])
                return {}; // Negattempe cycle detected.
        }
        return dist;
    }
}

// ------------------------- String Algorithms ------------------------- //
vector<int> computePrefix(const string &pattern)
{
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0;
    for (int i = 1; i < m; i++)
    {
        while (len > 0 && pattern[i] != pattern[len])
            len = lps[len - 1];
        if (pattern[i] == pattern[len])
            len++;
        lps[i] = len;
    }
    return lps;
}
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

vector<int> kmpSearch(const string &text, const string &pattern)
{
    vector<int> result;
    if (pattern.empty())
        return result;
    vector<int> lps = computePrefix(pattern);
    int i = 0, j = 0;
    while (i < text.size())
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == pattern.size())
        {
            result.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < text.size() && text[i] != pattern[j])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return result;
}

// ------------------------- Miscellaneous Algorithms ------------------------- //
int binarySearch(const vector<int> &arr, int target)
{
    int lo = 0, hi = arr.size() - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        a[i] = {x, y};
    }

    int m = 2 * n;
    vector<ull> c(m + 1, 0), p(m + 1, 0);

    auto ad = [&](vector<ull> &b, int i, ull v)
    {
        for (; i <= m; i += i & -i)
            b[i] ^= v;
    };
    auto ps = [&](vector<ull> &b, int i)
    {
        ull r = 0;
        for (; i > 0; i -= i & -i)
            r ^= b[i];
        return r;
    };
    auto rg = [&](vector<ull> &b, int l, int r) -> ull
    {
        if (l > r)
            return 0ULL;
        return ps(b, r) ^ ps(b, l - 1);
    };

    ull sd = 88172645463325252ULL;
    auto sm = [&](ull x) -> ull
    {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    };
    auto nx = [&]() -> ull
    {
        sd = sm(sd);
        return sd;
    };

    ull g = 0;
    string s;
    s.reserve(n);

    for (int i = 0; i < n; i++)
    {
        int u = a[i].first, v = a[i].second;
        ull h = nx();

        ull sc = rg(c, u, v);
        ull sp = rg(p, u, v) & 1ULL;

        ull f = sc ^ (sp ? 0ULL : h);
        g ^= f;

        ull od = 1ULL ^ sp;
        ad(c, u, f);
        ad(c, v, f);
        ad(p, u, od);
        ad(p, v, od);

        s.push_back(g ? '0' : '1');
    }

    cout << s << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        
    }
    return 0;
}
