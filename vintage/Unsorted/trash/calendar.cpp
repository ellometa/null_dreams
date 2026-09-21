#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);

#define newline <<'\n'

void solve() {
    string startday; 
    cin >> startday;
    int monthdays; 
    cin >> monthdays;

    int odd;
    if (startday == "monday") odd = 0;
    else if (startday == "tuesday") odd = 1;
    else if (startday == "wednesday") odd = 2;
    else if (startday == "thursday") odd = 3;
    else if (startday == "friday") odd = 4;
    else if (startday == "saturday") odd = 5;
    else if (startday == "sunday") odd = 6;

    for (int i = 0; i < monthdays; ++i) {

        int temp = (odd + i) % 7;
        cout << i + 1 << " "; 
        if (temp == 0) cout << "monday" newline;
        else if (temp == 1) cout << "tuesday" newline;
        else if (temp == 2) cout << "wednesday" newline;
        else if (temp == 3) cout << "thursday" newline;
        else if (temp == 4) cout << "friday" newline;
        else if (temp == 5) cout << "saturday" newline;
        else if (temp == 6) cout << "sunday" newline;

        
    }
}

int32_t main() {
    IOS;

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
