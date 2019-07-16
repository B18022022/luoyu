#include <stdio.h>
int main() {
    int a, b, sum = 0;
    printf("请输入金额：");
    scanf("%d", &a);
    while (b / 3) {
        b = a / 3;
        sum += b;
        b = b + a % 3;
        a = b;

    }
    printf("一共能喝%d瓶\n", sum);
    return 0;

}