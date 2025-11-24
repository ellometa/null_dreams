#include <stdio.h>
#include <stdint.h>

void print_binary(uint64_t val, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (int)((val >> i) & 1));
    }
}

void analyze_float(float f) {
    union {
        float f;
        uint32_t u;
    } data;

    data.f = f;

    uint32_t sign = (data.u >> 31) & 0x1;
    uint32_t exponent = (data.u >> 23) & 0xFF;
    uint32_t mantissa = data.u & 0x7FFFFF;
    int exponent_decimal = (int)exponent - 127;

    printf("\nSingle Precision (float) IEEE 754 representation:\n");
    printf("Sign: %u\n", sign);
    printf("Exponent (decimal, biased): %u\n", exponent);
    printf("Exponent (decimal, unbiased): %d\n", exponent_decimal);
    printf("Exponent (binary): ");
    print_binary(exponent, 8);
    printf("\n");
    printf("Mantissa (decimal): %u\n", mantissa);
    printf("Mantissa (binary): ");
    print_binary(mantissa, 23);
    printf("\n");
}

void analyze_double(double d) {
    union {
        double d;
        uint64_t u;
    } data;

    data.d = d;

    uint64_t sign = (data.u >> 63) & 0x1;
    uint64_t exponent = (data.u >> 52) & 0x7FF;
    uint64_t mantissa = data.u & 0xFFFFFFFFFFFFF;
    int exponent_decimal = (int)exponent - 1023;

    printf("\nDouble Precision (double) IEEE 754 representation:\n");
    printf("Sign: %llu\n", sign);
    printf("Exponent (decimal, biased): %llu\n", exponent);
    printf("Exponent (decimal, unbiased): %d\n", exponent_decimal);
    printf("Exponent (binary): ");
    print_binary(exponent, 11);
    printf("\n");
    printf("Mantissa (decimal): %llu\n", mantissa);
    printf("Mantissa (binary): ");
    print_binary(mantissa, 52);
    printf("\n");
}

int main() {
    int choice;
    printf("1. Single precision (float)\n2. Double precision (double)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        float num;
        printf("Enter a decimal number: ");
        scanf("%f", &num);
        analyze_float(num);
    } else if (choice == 2) {
        double num;
        printf("Enter a decimal number: ");
        scanf("%lf", &num);
        analyze_double(num);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
