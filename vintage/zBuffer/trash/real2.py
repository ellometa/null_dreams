MOD = 998244353

# Function to calculate the result for a given n
def calculate_modular_value(n):
    result = 0
    length = 1
    while length <= n:
        max_number_in_this_bit_range = (1 << length) - 1
        start = 1 << (length - 1)
        end = min(max_number_in_this_bit_range, n)
        count = end - start + 1
        for num in range(start, end + 1):
            result = (result * (1 << length) + num) % MOD
        length += 1
    return result

# Reading input and processing the test cases
t = int(input())
n_values = list(map(int, input().split()))

for n in n_values:
    print(calculate_modular_value(n))
