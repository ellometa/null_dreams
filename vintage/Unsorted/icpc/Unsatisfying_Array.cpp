#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    int n, k;
    cin >> n >> k;

    vector<int> vecarr;
    int rprev = INF;

    bool flag= false;

    for (int i = 0; i < k; i++) {
        int l, r, m;
        cin >> l >> r >> m;

        if (l!=m){
            vecarr.push_back(l);
        }
        else{
            flag = true;
        }
        rprev = r;
    }
    vecarr.push_back(rprev);

    sort(all(vecarr));


    // for(auto &x:vecarr){cout << x;}
    int la = vecarr[0], ra = vecarr[vecarr.size()-1];

    if (flag){
        cout << "-1" newline; return;
    }

    for (int i = la; i <= ra; i++){
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
/*
n, k
array of length n

k triplets given

1 3      2
l r      m


*/
