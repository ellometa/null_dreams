#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF LLONG_MAX >> 1

void solve(){
    

    string p = "ZZZZZzZZZZZ", ciphertext;

    for (auto &a: p){ a = toupper(a);}

    int key = 2;

    for(int i = 0; i < (int)p.size(); i++){
        
        int ans = (int(p[i]-'A') + key)%26;

        ciphertext+=char(ans+65);
    
    }

    cout << ciphertext;

}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ll test=1;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}