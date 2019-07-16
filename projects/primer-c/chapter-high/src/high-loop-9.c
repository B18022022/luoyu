#include <stdio.h>
int main() {
    int i,j,k;
    for (i = 0; i <= 100; i++) {
        for (j = 0; j <= 50; j++) {
            for (k = 0; k <= 20; k++){
                if (i + 2*j + 5*k == 100)
                    printf("一分钱：%d枚，二分钱：%d枚，五分钱：%d枚\n", i, j, k);
            }
        }

    }
    return 0;
}
