#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

int main() {
    IOS;

    int t, n, sum=0;    cin >> t; 
    for (int i=0; i<t; i++){
        cin >> n;
        sum+=n;
    }
    cout << sum;
    return 0;
}
