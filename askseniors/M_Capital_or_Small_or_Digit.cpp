#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
// #define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    char c; cin>>c;
    int n = int(c);
    // cout << n;

    if (n<65){
        cout << "IS DIGIT";
        return;
    }
    else if (n<97){
        cout << "ALPHA" newline << "IS CAPITAL";
        return;
    }
    else{
        cout << "ALPHA" newline << "IS SMALL";
    }

}

int main() {
    IOS;

    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}