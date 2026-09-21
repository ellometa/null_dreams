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
    int oddcounter=0, evencounter=0;

    for (int i =1; i<=(n/2); i++ ){
        if(n%i==0){
            i%2==0?evencounter++:oddcounter++;
        }
    }

    n%2==0?evencounter++:oddcounter++;

    if(oddcounter>evencounter){
        cout << "-1" newline;
    }
    else if(evencounter>oddcounter){
        cout << "1" newline;
    }
    else{
        cout << "0" newline;
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