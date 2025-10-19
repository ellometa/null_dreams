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

void solve() {

    int n; cin>>n;
    int counter = 0;
    for (int j = 2; j<=n; j++){
        int factor = 0;
        // cout << "j " << j newline;
        for (int i = 1; i <= j; i++){
            
            if(j%i == 0 && isPrime(i)){
                // cout << "i " << i newline;
                factor+=1;
            }
            
            
        }
        if (factor == 2){
            counter +=1;
        }
    }   
    
    cout << counter;
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