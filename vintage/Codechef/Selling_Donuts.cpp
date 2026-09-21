#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    int n, m; cin>>n>>m;

    vector<int> donuts(n);
    for(auto &x:donuts){cin>>x;}

    int counter=0;

    for (int i = 0; i<m; i++){
        int temp; cin >> temp;

        if(donuts[temp-1]>0){
            donuts[temp-1]-=1;
            ++counter;
        }

    }

    cout << m-counter newline;
    

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
1...........N
.....A
1...........M
..B

*/