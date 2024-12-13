#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {
    string line;

    int counter = 0;
    while (getline(cin, line)) { 

        // int counter = 0;

        stringstream ss(line); 
        int number;
        
        vector<int> vecarr;
        
        int temp = 0;
        while (ss >> number) {
            // cout << number-temp << " over here " newline;
            vecarr.push_back(number-temp);
            temp = number;
        }
        vecarr.erase(vecarr.begin());
        // for (auto &x:vecarr){
        //     cout << vecarr[0];
        // }

        bool flag = true;

        if (vecarr[0] < 0){
            
            for (auto &x:vecarr){
                // cout << x << " here " newline;
                if (x==-1 || x==-2 || x == -3){
                    continue;
                } 
                else{
                    flag = false;
                }
            }
            if (flag) counter+=1;
        }
        else{
            for (auto &x:vecarr){
                // cout << x << " here";
                if (x ==2 || x==1 || x==3){
                    continue;
                } 
                else{
                    flag = false;
                }
            }
            if (flag) counter+=1;
        }
        
        // cout << counter newline;

    }

    cout << counter newline;
}

int32_t main() {
    IOS;
    solve();
    return 0;
}
