#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    int n; cin>>n;
    int sum = 0;
    for (int i =0; i<n; i++){
        int temp; cin >> temp;
        sum+=temp;
    }


    if (n==1){
        cout << "NO" newline;
    }
    else if (sum > n+1){
        cout << "YES" newline;
    }

    else{
        cout << "NO" newline;
    }

}

int32_t main() {
    IOS;

    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}