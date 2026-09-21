#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);


    int n,x;
    cin >> n >> x;
    unordered_map <int, int> prefixCount;
    prefixCount.reserve(n+1);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int prefixSum = 0, count = 0;
    prefixCount[0] = 1;
    for (int num : arr) {
        prefixSum += num;
        count += prefixCount[prefixSum - x]; 
        prefixCount[prefixSum]++; 
    }
    cout << count << endl;
    
    return 0;
}