#include <iostream>
#include <cmath>
using namespace std;

long long largest_prime_factor(long long n) {
    long long max_prime = -1;


    while (n % 2 == 0) {
        max_prime = 2;
        n /= 2;
    }


    for (long long i = 3; i <= std::sqrt(n); i += 2) {
        while (n % i == 0) {
            max_prime = i;
            n /= i;
        }
    }


    if (n > 2)
        max_prime = n;

    return max_prime;
}


void solve (){
    long long n; cin >> n;
    std::cout << largest_prime_factor(n) << std::endl;

}

int main() {
    int t; cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}