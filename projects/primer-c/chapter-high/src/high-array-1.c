#include <stdio.h>
int main() {
    int a[7] = {8, 54, 27, 11, 23, 344, 82};
    int i, j, temp;

    for (i = 0; i < 6; i++)
        for (j = i; j < 6; j++) {
            if (a[j + 1] < a[j]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }

    for (i = 0; i < 7; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}