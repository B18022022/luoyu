#include <stdio.h>
int factorial(int x) {
    int s = 1;

    while (x) {
        s *= x;
        x --;
    }

    return s;
}
int combination(int n, int r) {
    int q;
    q = (factorial(n) / (factorial(r) * factorial((n - r))));
    return q;
}
int main() {
    int a, b;
    printf("请输入组合数mCn中的m和n的值:\n");
    printf("请输入m的值：");
    scanf("%d", &a);
    printf("请输入n的值：");
    scanf("%d", &b);
    printf("结果为%d\n", combination(a, b));
    return 0;
}