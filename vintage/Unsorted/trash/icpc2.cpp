#include <bits/stdc++.h>
using namespace std;

#define ICPC WINNERS WOOO!!!

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
// const int INF = LLONG_MAX >> 1;

void solve() {
    vector<int> vec1;
    int size;
    int k;
    cin >> size >> k;
    for(int i = 0; i < size; i++){
        int k;
        cin >> k;
        vec1.push_back(k);
    }
    sort(all(vec1));
    int answer = 0;
    int prefSum = 0;
    int discount = 0;
    int curr = 0;
    for(int i = 0; i < size; i++){
        prefSum += vec1[i];
        answer = prefSum;
        if((i%k == 0) && (size - i) < k + 1) {
            discount += vec1[i];
        }
        if(i > k) answer -= discount;
        cout << answer << " ";
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

