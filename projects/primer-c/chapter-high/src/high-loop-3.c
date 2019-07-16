#include <stdio.h>
int main() {
    int a, b, i;

    printf("请输入一个数字：");
    scanf("%d", &a);
    
    b = a / 2;
    for (i = 2; i < b; i++) {
        if (a % i == 0) {
            printf("这是一个合数\n");
            break;
        }
    }
    if (i == b)
        printf("这是一个素数\n");
    return 0;
}