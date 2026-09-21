#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int findbit(int m, int q) {
    m = abs(m) > abs(q) ? abs(m) : abs(q);
    int power = 0;
    while (pow(2, power) < m) power++;
    return (power + 1 > 4) ? power + 1 : 4;
}

int* binary(int a, int num) {
    int* ptr = (int*)malloc(num * sizeof(int));
    int acopy = abs(a), check = 1;

    for (int i = 0; i < num; i++) {
        ptr[i] = acopy % 2;
        acopy = acopy / 2;
    }

    if (a < 0) {
        for (int i = 0; i < num; i++) {
            if (ptr[i] == 1 && check == 1)
                check = 0;
            else if (ptr[i] == 1 && check == 0)
                ptr[i] = 0;
            else if (ptr[i] == 0 && check == 0)
                ptr[i] = 1;
        }
    }

    return ptr;
}

void printbinary(int* ans, const char* s, int num) {
    for (int i = 2 * num; i > num; i--)
        printf("%d ", ans[i]);
    printf("\t");
    for (int i = num; i > 0; i--)
        printf("%d ", ans[i]);
    printf("\t%d\t%s\n", ans[0], s);
}

void binaryadd(int* ans, int* n, int num) {
    int carry = 0;
    for (int i = num + 1; i <= 2 * num; i++) {
        int sum = ans[i] + n[i - num - 1] + carry;
        ans[i] = sum % 2;
        carry = sum / 2;
    }
}

int main() {
    int m, q;
    printf("Enter M and Q: ");
    scanf("%d %d", &m, &q);

    int num = findbit(m, q);
    int* ans = (int*)calloc(2 * num + 1, sizeof(int));
    int* arr = binary(q, num);

    for (int i = num; i > 0; i--)
        ans[i] = arr[i - 1];

    printf("\nA\t\tQ\t\tQ-1\t\tOperation\n\n");
    printbinary(ans, "Initial Value", num);

    for (int i = 0; i < num; i++) {
        if (ans[1] == 0 && ans[0] == 1) {
            int* m_bin = binary(m, num);
            binaryadd(ans, m_bin, num);
            printbinary(ans, "A := A + M", num);
            free(m_bin);
        } else if (ans[1] == 1 && ans[0] == 0) {
            int* negm_bin = binary(-m, num);
            binaryadd(ans, negm_bin, num);
            printbinary(ans, "A := A - M", num);
            free(negm_bin);
        }

        // Arithmetic Right Shift
        for (int j = 0; j < 2 * num; j++)
            ans[j] = ans[j + 1];
        printbinary(ans, "Arithmetic Right Shift", num);
    }

    printbinary(ans, "Final Answer", num);

    free(ans);
    free(arr);
    return 0;
}
