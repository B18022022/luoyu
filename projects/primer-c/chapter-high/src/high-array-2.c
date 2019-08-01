#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, i , m = 0, k = 0;
    printf("请输入人的个数n:");
    scanf("%d", &n);
    
    int *p = (int *)calloc(n , sizeof(int));

    for (i = 0; i < n; i++) {
        *(p + i) = i + 1;
    }

    i = 0;

    while (m < n - 1) {
        if (*(p + i) != 0) {
            k++;
        }

        if (k == 3) {
            *(p + i) = 0;
            k = 0;
            m++;
        }

        i++;

        if (i == n) {
            i = 0;
        }
    }

    while (*p == 0) {
        p++;
    }

    printf("最后一个人的号码是%d.\n", *p);
    return 0;
}