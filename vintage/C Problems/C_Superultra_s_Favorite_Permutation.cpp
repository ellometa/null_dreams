#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    int n; cin >> n;

    if (n<5){ cout << "-1" newline; return;}

    //print the odds
    cout << "1 3 ";
    for (int i=7; i<=n;i+=2){
        cout<< i << " ";
    }
    cout <<"5 4 2 ";
    //print rest of the even
    for (int i = 6; i <=n; i+=2){
        cout << i << " ";
    }
    cout newline;
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