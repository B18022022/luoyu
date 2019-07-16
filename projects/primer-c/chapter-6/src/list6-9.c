#include <stdio.h>
void rev_intary(int v[], int n) {
    int m[n],i;
    for (i = 0; i < n; i++) {
        m[i] = v[n - i - 1];
    }
    for (i = 0; i < n; i++) {
        printf("%d ", m[i]);
    }
}
int main() {
    int i, n;
    int v[100];
    printf("请输入数组的个数:");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("第%d个数字:", i + 1);
        scanf("%d", &v[i]);
    }
    rev_intary(v, n);
    return 0;
}
