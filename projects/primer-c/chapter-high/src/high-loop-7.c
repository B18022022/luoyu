#include <stdio.h>
int main() {
    double i = 0.00008, a = 8848.13;
    int count = 0;
    while (i < a) {
        i *= 2;
        count++;
    }
    printf("%d\n", count);
    return 0;
}