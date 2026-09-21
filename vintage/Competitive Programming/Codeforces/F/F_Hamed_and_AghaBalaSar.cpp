
#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1'000'000'007;

// fast pow
long long modpow(long long a, long long e=MOD-2){
    long long r=1;
    while(e){
        if(e&1) r=r*a%MOD;
        a=a*a%MOD; e>>=1;
    }
    return r;
}

struct Comb {
    vector<long long> fact, ifact;
    Comb(int N=0){ init(N); }
    void init(int N){
        fact.resize(N+1);
        ifact.resize(N+1);
        fact[0]=1;
        for(int i=1;i<=N;i++) fact[i]=fact[i-1]*i%MOD;
        ifact[N]=modpow(fact[N]);
        for(int i=N;i>0;i--) ifact[i-1]=ifact[i]*i%MOD;
    }
    long long C(long long n, long long k) const {
        if(n<0 || k<0 || k>n) return 0;
        return fact[n] * ifact[k] % MOD * ifact[n-k] % MOD;
    }
};

// count sequences of length r, sum x, values in [0..U]
long long bounded_cnt(int r, int x, int U, const Comb& C){
    if(r==0) return (x==0);
    if(x<0) return 0;
    if(1LL*r*U < x) return 0;
    // inclusion-exclusion on upper bound
    int J = x / (U+1);
    long long ans = 0;
    for(int j=0;j<=J;j++){
        long long term = C.C(r, j) * C.C(x - 1LL*j*(U+1) + r - 1, r - 1) % MOD;
        if(j&1) ans = (ans - term + MOD) % MOD;
        else    ans = (ans + term) % MOD;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if(!(cin>>T)) return 0;
    vector<pair<int,int>> qs(T);
    int maxN=0, maxM=0;
    for(int i=0;i<T;i++){
        int n,m; cin>>n>>m;
        qs[i]={n,m};
        maxN = max(maxN, n);
        maxM = max(maxM, m);
    }
    // we need nCk up to ~ (n-1 + m)
    int LIM = maxN - 1 + maxM + 5;
    Comb C(LIM);

    for(auto [n,m] : qs){
        int L = n-1;
        long long invL = modpow(L);
        long long ans = 0;

        for(int M=0; M<=m; M++){
            int S = m - M;
            if(1LL*L*M < S) continue; // impossible

            long long cntAll = bounded_cnt(L, S, M, C);
            long long cntFirstM = (S >= M ? bounded_cnt(L-1, S - M, M, C) : 0);

            long long factor = ((1LL*L*M - S) % MOD + MOD) % MOD;
            factor = factor * invL % MOD;

            long long ways = (cntAll + 1LL*L*cntFirstM) % MOD;

            ans = (ans + factor * ways) % MOD;
        }

        cout << ans % MOD << endl;
    }
    return 0;
}

