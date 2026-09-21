
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


typedef unsigned char byte;

int count = 0; 
vector<int> primes;
void sieve(int lim)
{
    if (lim < 2) return ;
    int sqrt = std::sqrt(lim);
    int sieve_size = max(sqrt, (1 << 15));
    int segment_size = sieve_size * 16;

    vector<BYTE> mark(sieve_size);
    vector<BYTE> is_prime(sqrt + 1, true);
    vector<int> seg_prime;
    vector<int> seg_multi;

    for (int i = 3; i <= sqrt; i += 2)
        if (is_prime[i])
            for (int j = i * i; j <= sqrt; j += i)
                is_prime[j] = false;

    int reset[16];
    for (int i = 0; i < 8; ++i)
        reset[2 * i] = reset[2 * i + 1] = ~(1 << i);

    int popcnt[256];
    for (int i = 0; i < 256; ++i)
        popcnt[i] = __builtin_popcount(i);

    int s = 3;
    for (int low = 0; low <= lim; low += segment_size)
    {
        fill(mark.begin(), mark.end(), 0xff);
        int high = min(low + segment_size - 1, lim);
        sieve_size = (high - low) / 16 + 1;

        for (; s * s <= high; s += 2)
        {
            if (is_prime[s])
            {
                seg_prime.push_back(s);
                seg_multi.push_back(s * s - low);
            }
        }

        for (size_t i = 0; i < seg_prime.size(); ++i)
        {
            int j = seg_multi[i];
            for (int k = seg_prime[i] * 2; j < segment_size; j += k)
                mark[j >> 4] &= reset[j % 16];

            seg_multi[i] = j - segment_size;
        }

        if (high == lim)
        {
            int bits = 0xff << ((lim % 16) + 1) / 2;
            mark[sieve_size - 1] &= ~bits;
        }
        
        for (int n = 0; n < sieve_size; n++)
        {
//             count += popcnt[mark[n]]; continue;
            for (int i = 0; i < 8; i++)
                if (mark[n] & (1 << i))
                    primes.push_back(low + n * 16 + i * 2 + 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    sieve(n);
    int p = primes.size();
    cout << p << endl;
    return 0;
}