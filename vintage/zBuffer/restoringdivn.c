#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void decimalToBinary(int n_dec, int arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        arr[i] = n_dec % 2;
        n_dec = n_dec / 2;
    }
}

void binaryAdd(int accumulator[], int arr[], int n) {
    int carry = 0;
    for (int i = n; i >= 0; i--) {
        int sum = accumulator[i] + arr[i] + carry;
        accumulator[i] = sum % 2;
        carry = sum / 2;
    }
}

void calculateTwosComplement(int divisor[], int divisor_comp[], int n) {
    int size = n + 1;
    int temp_comp[size];
    int carry = 1;

    // Bitwise NOT of divisor
    for (int i = 0; i < size; i++) {
        temp_comp[i] = (divisor[i] == 0) ? 1 : 0;
    }

    // Add 1 to get 2's complement
    for (int i = n; i >= 0; i--) {
        int sum = temp_comp[i] + carry;
        divisor_comp[i] = sum % 2;
        carry = sum / 2;
    }
}

void leftShift(int accumulator[], int quotient[], int n) {
    // Shift accumulator left by 1 (except last bit)
    for (int i = 0; i < n; i++) {
        accumulator[i] = accumulator[i + 1];
    }

    // The last bit of accumulator takes first bit of quotient
    accumulator[n] = quotient[0];

    // Shift quotient left by 1
    for (int i = 0; i < n - 1; i++) {
        quotient[i] = quotient[i + 1];
    }
    quotient[n - 1] = 0; // Vacated bit becomes 0
}

void printRegisters(const char* step_name, int accumulator[], int quotient[], int n) {
    char a_str[n + 1];
    char q_str[n + 1];

    // Print accumulator bits from index 1 to n (skip sign bit at index 0)
    for (int i = 0; i < n; i++) {
        a_str[i] = accumulator[i + 1] + '0';
    }
    a_str[n] = '\0';

    // Print quotient bits
    for (int i = 0; i < n; i++) {
        q_str[i] = quotient[i] + '0';
    }
    q_str[n] = '\0';

    printf("%-20s %-20s %s\n", a_str, q_str, step_name);
}

long long binaryToDecimal(int arr[], int size) {
    long long value = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 1) {
            value += (long long)pow(2, size - 1 - i);
        }
    }
    return value;
}

int main() {
    int dividend_dec, divisor_dec;
    int n;

    printf("Enter the number of bits for the operation (e.g., 4, 8, 10): ");
    scanf("%d", &n);

    if (n <= 0 || n > 18) {
        printf("Number of bits must be positive and not excessively large.\n");
        return 1;
    }

    int *accumulator = (int*)malloc((n + 1) * sizeof(int));
    int *divisor = (int*)malloc((n + 1) * sizeof(int));
    int *divisor_comp = (int*)malloc((n + 1) * sizeof(int));
    int *quotient = (int*)malloc(n * sizeof(int));

    if (!accumulator || !divisor || !divisor_comp || !quotient) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    memset(accumulator, 0, (n + 1) * sizeof(int));
    memset(divisor, 0, (n + 1) * sizeof(int));
    memset(divisor_comp, 0, (n + 1) * sizeof(int));
    memset(quotient, 0, n * sizeof(int));

    printf("Enter Dividend (Q): ");
    scanf("%d", &dividend_dec);
    printf("Enter Divisor (M): ");
    scanf("%d", &divisor_dec);
    printf("\n");

    decimalToBinary(dividend_dec, quotient, n);
    decimalToBinary(divisor_dec, divisor, n + 1);
    calculateTwosComplement(divisor, divisor_comp, n);

    printf("Dividend (Q) = %d\n", dividend_dec);
    printf("Divisor  (M) = %d\n\n", divisor_dec);

    printf("%-20s %-20s %s\n", "Accumulator (A)", "Quotient (Q)", "Step");
    printRegisters("Initial", accumulator, quotient, n);

    for (int count = n; count > 0; count--) {
        printf("\n");
        leftShift(accumulator, quotient, n);
        printRegisters("Left Shift", accumulator, quotient, n);

        int *temp_accumulator = (int*)malloc((n + 1) * sizeof(int));
        memcpy(temp_accumulator, accumulator, (n + 1) * sizeof(int));

        binaryAdd(accumulator, divisor_comp, n);
        printRegisters("A = A - M", accumulator, quotient, n);

        if (accumulator[0] == 1) {  // If sign bit is set, negative result
            memcpy(accumulator, temp_accumulator, (n + 1) * sizeof(int));
            quotient[n - 1] = 0;
            printRegisters("Restore A, q0=0", accumulator, quotient, n);
        } else {
            quotient[n - 1] = 1;
            printRegisters("A >= 0, q0=1", accumulator, quotient, n);
        }
        free(temp_accumulator);
    }

    printf("Final Result:\n");

    long long quotient_res = binaryToDecimal(quotient, n);
    long long remainder_res = binaryToDecimal(accumulator + 1, n);

    printf("Quotient (Q)  = %lld\n", quotient_res);
    printf("Remainder (A) = %lld\n", remainder_res);

    free(accumulator);
    free(divisor);
    free(divisor_comp);
    free(quotient);

    return 0;
}