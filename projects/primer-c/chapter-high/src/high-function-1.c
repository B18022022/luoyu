#include <stdio.h>
int function(int a, int b, int c) {
    if (a > 0 && b > 0 && c > 0 && (a + b) > c && (b + c) > a && (c + a) > b) {
        if (a == b && b == c) {
            return 3;
        } else if (a == b || b == c || a == c) {
            return 2;
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}
int main() {
    int a, b, c;
    printf("请输入三角形三边a,b,c的值:\n");
    printf("三角形边a的值是:");
    scanf("%d", &a);
    printf("三角形边b的值是:");
    scanf("%d", &b);
    printf("三角形边c的值是:");
    scanf("%d", &c);
    printf("返回值是%d\n", function(a, b, c));
    return 0;
}