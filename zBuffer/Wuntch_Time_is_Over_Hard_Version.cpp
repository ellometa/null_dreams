#include <bits/stdc++.h>
using namespace std;

// #define fio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); freopen("Error.txt", "w", stderr)
// #define sorti(arg) sort(arg.begin(), arg.end())
// #define rev(arg) reverse(arg.begin(), arg.end())
// #define yno(arg) if (arg) cout << "ALICE\n"; else cout << "BOB\n";
// #define sz(arg) (int)(arg.size())
using ll = long long;
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
  
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

const int N = 1e6+10;
vector<int> prime(N,(int)1);
vector<int> cnt(N,0);
void sieve(){
    prime[0] = prime[1] = 0;
    for(int i = 2;i < N;i++){
        if(prime[i]){
            for(int j = i+i;j < N;j += i){
                prime[j] = 0;
            }
        }
    }
}
const int mod = 1e9 + 7;
#define int long long
const int lim = 1e12 + 100;

void haha() {
    for(int i = 1;i < N;i++){
        for(int j = i;j < N;j += i){
            cnt[j]++;
        }
    }
    ordered_set st;
    vector<int> pr,pwr;
    for(int i = 2;i < N;i++){
        if(prime[i]){
            pr.push_back(i);
            if(i > 2 && i <= 55)pwr.push_back(i-1);
        }
    }
    for(auto &p : pr){
        for(auto pp : pwr){
            int j = 1;
            while(pp--){
                j *= p;
                if(j >= lim)break;
                // st.insert(j);
            }
            if(j <= lim)st.insert(j);
        }
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        int y = st.order_of_key(r + 1);
        int x = st.order_of_key(l);
        cout << y - x << endl;
    }
}

signed main() {
    fio();
    int TC = 1;
    sieve();
    // cin >> TC;
    while (TC--) {
        haha();
    }
}