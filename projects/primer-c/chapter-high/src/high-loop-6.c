#include <stdio.h>
int main() {
    int j, i, high, a, b;
    printf("请输入高度:");
    scanf("%d", &high);
    a = high / 2;
    b = a - 1;

    for (i = 0; i < high; i++) {
        for (j = 0; j < high - i - 1; j++) {
            putchar(' ');
        }

        for (j = 0; j < i * 2 + 1; j++) {
            putchar('*');
        }

        printf("\n");
    }

    printf("\n");

    for (i = 0; i < high; i++) {
        for (j = 0; j < i; j++) {
            putchar(' ');
        }

        for (j = 0; j < (high - i) * 2 - 1; j++) {
            putchar('*');
        }

        printf("\n");
    }

    printf("\n");

    for (i = 0; i < a; i++) {
        for (j = 0; j < a - i - 1; j++) {
            putchar(' ');
        }

        for (j = 0; j < i * 2 + 1; j++) {
            putchar('*');
        }

        printf("\n");
    }

    for (i = 0; i < b; i++) {
        for (j = 0; j < i + 1; j++) {
            putchar(' ');
        }

        for (j = 0; j < (b - i) * 2 - 1; j++) {
            putchar('*');
        }

        printf("\n");
    }

    return 0;

}