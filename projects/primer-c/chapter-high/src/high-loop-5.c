#include <stdio.h>
int main() {
    double i, a, b;
    a = 10000;
    b = 0.003;

    for (i = 0; i < 5; i++) {
        a = a + a * b;
    }

    printf("5年后可获取%f\n", a);
    return 0;
}