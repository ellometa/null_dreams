#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {
    int n ; cin >> n;


    for (int i = 1; i<=n; i++){
        
        for (int j = 1; j<=n-i; j++){
            cout << " ";
        }
        for (int k= 1; k<=2*i-1; k++){
            cout << "*";
        }
        cout newline;
    }

    // for (int i = n; i >= 1; i--){

    //     for (int j = n-i; j >= 1; j--){
    //         cout << " ";
    //     }

    //     for(int k=2*i-1; k >= 1; k--){
    //         cout << "*";
    //     }
    //     cout newline;

    // }


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
/*

   *
  ***
 *****
*******


*******
 *****
  ***
   *

  *
 ***
*****
*******

*/