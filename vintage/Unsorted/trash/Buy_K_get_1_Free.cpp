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
    //int answer = 0;
    vector<int> prefsum(size,0);
    vector<int> discountsum(size + 1, 0);
    int num = 0;
    for(int i = 0; i < size; i++){
        num += vec1[i];
        prefsum[i] = num;
        if(i < k ){
            discountsum[i+1] = vec1[i];
            cout << prefsum[i] << " ";
            continue;
        }
        else if(i- (2 * k + 1) >= 0) discountsum[i+1] = vec1[i-k] + discountsum[i - (k)];
        else discountsum[i+1] = vec1[i-k];
        cout << prefsum[i] - discountsum[i+1] << " "; 
    }
    /*for(int i = 0; i < size; i++){
        answer = prefsum[i];
        if(i < k){
            cout << answer << " ";
            continue;z
        }
        int j = i-k;
        while(j >= 0){
            answer-= vec1[j];
            j = j - (k+1);
            // cout << j << " <--- j,      vec[j]--->" << vec1[j] newline;
            // cout << j << " <--- j,      k+1--->" << k newline;
        }
        cout << answer << " ";
    }*/
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



*/