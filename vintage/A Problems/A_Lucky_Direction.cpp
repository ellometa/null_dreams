#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    string s; cin >> s;
    if (s=="N"){cout << "S" newline;}
    else if (s=="S"){cout << "N" newline;}
    else if (s=="W"){cout << "E" newline;}
    else if (s=="E"){cout << "W" newline;}
    else if (s=="NW"){cout << "SE" newline;}
    else if (s=="NE"){cout << "SW" newline;}
    else if (s=="SW"){cout << "NE" newline;}
    else if (s=="SE"){cout << "NW" newline;}

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