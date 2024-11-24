#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);

void solve() {
    int size;
    int k;
    cin >> size >> k;
    vector<int> indices;
    vector<int> values;

    for (int i = 0; i < size; i++) {
        int num;
        cin >> num;
        if (num < k) continue;
        else if ((num & k) == k && k%2 == 0) {
                indices.push_back(i);
                values.push_back(num);
        }
        else if ((num & k) == k) {
            if (num % 2 == 1) {
                indices.push_back(i);
                values.push_back(num);
            }
        }
    }
    if (values.empty() || indices.empty()) {
        cout << "NO" << '\n';
        return;
    }
    else if (values.size() == 1) {
        if (values[0] != k) {
            cout << "NO" << '\n';
            return;
        }
        cout << "YES" << '\n' << "1" << '\n' << (indices[0] + 1) << '\n';
        return;
    }
    while (k > 0) {
        bool found = false;
        for (int i = 0; i < values.size(); i++) {
            if ((k & 1) == 1) {
                if (values[i] == -1) continue;
                else if ((values[i] & 1) == 0) {
                    values[i] = -1;
                    indices[i] = -1;
                }
                else {
                    found = true;
                }
                values[i] >>= 1;
            }
            else {
                if ((values[i] & 1) == 0) {
                    found = true;
                }
                values[i] >>= 1;
            }
        }
        if (!found) {
            cout << "NO" << '\n';
            return;
        }
        k >>= 1;
    }
    cout << "YES" << '\n' << values.size() << '\n';
    for (int i = 0; i < values.size(); i++) {
        cout << (indices[i] + 1) << " ";
    }
    cout << '\n';

}


int main() {
    IOS;
    int limit;
    cin >> limit;
    for (int i = 0; i < limit; i++) solve();

}

