#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    float a,b; cin >> a >> b;

    if (a == 0){
        if (b==0){
            cout << "Origem";
            return;
        }
        cout << "Eixo Y";
    }
    else if (b==0){
        cout << "Eixo X";
    }
    else if (a>0 && b > 0){
        cout << "Q1" ;
    }
    else if (a<0 && b > 0){
        cout << "Q2" ;
    }
    else if (a>0 && b < 0){
        cout << "Q4" ;
    }
    else if (a<0 && b<0){
        cout << "Q3" ;
    }



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