#include <stdio.h>
#include <math.h>

void printBinary(int num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}
int main() {
    int dividend, divisor;
    printf("Enter Dividend: ");
    scanf("%d", &dividend);
    printf("Enter Divisor: ");
    scanf("%d", &divisor);
    int n = (int)log2(dividend) + 1;
    int A = 0, Q = dividend, M = divisor;
    printf("\nRestoring Division Operation:\n");
    printf("Step\tA\t\tQ\t\tOperation\n");
    for (int i = 1; i <= n; i++) {
        int msbQ = (Q >> (n - 1)) & 1;
        A = (A << 1) | msbQ;
        Q = (Q << 1) & ((1 << n) - 1);
        if (A >= 0) {
            A = A - M;
            if (A >= 0)
                Q = Q | 1; 
            printf("%d\t", i);
            printBinary(A, n + 1);
            printf("\t\t");
            printBinary(Q, n);
            printf("\t\tA = A - M\n");
        } else {
            A = A + M;
            if (A >= 0)
                Q = Q | 1;
            printf("%d\t", i);
            printBinary(A, n + 1);
            printf("\t\t");
            printBinary(Q, n);
            printf("\t\tA = A + M\n");
        }
    }
    if (A < 0)
        A = A + M;
    printf("\nFinal Quotient (Q) = ");
    printBinary(Q, n);
    printf(" (decimal %d)\n", Q);

    printf("Final Remainder (A) = ");
    printBinary(A, n + 1);
    printf(" (decimal %d)\n", A);
    return 0;
}
