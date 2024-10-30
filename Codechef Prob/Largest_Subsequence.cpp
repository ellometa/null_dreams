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

    string s; cin>>s;
    int counter=0;
    for (int i = 0; i< n;i++){
        if (s[i]==s[0]){
            counter = max(counter, i+1);
        }
        if (s[i]==s[n-1]){
            counter=max(counter,n-i);
        }
    }
    cout << counter newline;
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

/*
 
ab, aa, a, aba 
 
aba

a
b
ab
aa
ba


aaaaaaaaaaabb
bbbbbbbbbbbaa



*/
