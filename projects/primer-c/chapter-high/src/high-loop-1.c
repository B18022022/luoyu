#include <stdio.h>
int main(void) {
    int n, i = 0, sum = 0, x;
    printf("请输入n个整数！");
    scanf("%d", &n);

    while (n) {
        printf("请输入第%d个整数：", i + 1);
        scanf("%d", &x);
        sum += x ;
        i++;
        n--;
    }

    printf("和为%d\n", sum);
    return 0;
}