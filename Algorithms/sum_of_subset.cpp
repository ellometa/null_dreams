#include <iostream>
using namespace std;

int a[100], res[100];
int n, target;
bool flag = false;

void solve(int i, int size, int current_sum) {
    if (current_sum == target) {
        flag = true;
        for (int j = 0; j < size; j++) {
            cout << res[j] << " ";
        }
        cout << endl;
        return;
    }

    if (i == n || current_sum > target) {
        return;
    }

    res[size] = a[i];
    solve(i + 1, size + 1, current_sum + a[i]);
    solve(i + 1, size, current_sum);
}

int main() {
    cout << "Enter n: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    cout << "Results:" << endl;
    solve(0, 0, 0);

    if (flag == false) {
        cout << "No subset found" << endl;
    }
    return 0;
}
