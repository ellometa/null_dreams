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
    int k; cin >> k;
    vector<int> v(n);

    vector<int> freq(n, 0);

    int counter = 0, indexa;
    for (int i = 0; i < n; i++){
        int temp; cin >> temp;
        v.push_back(temp%k);
    }


    bool flag ;
    for(int i = 0; i < n; i++){
        flag = true;
        for(int j = 0; j < n; j++){
            if (v[i] == v[j] && i!=j){
                flag = false;
            }
        }
        if (flag == true){
            cout << "YES" newline << i+1 newline;
            return;
        }
    }
    cout << "NO" newline; 

    // if (counter==1){
    //    out << "YES" newline << indexa  newline;
    // }
    // else{
    //     cout << "NO" newline; 
    // }


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