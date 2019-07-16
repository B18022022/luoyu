#include <stdio.h>
void rev_intary(int v1[], int v2[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        v1[i] = v2[n - i - 1];
    }
}
int main() {
    int i, n;
    int v2[100];
    int v1[100];
    printf("请输入数组的个数:");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("第%d个数字:", i + 1);
        scanf("%d", &v2[i]);
    }
    rev_intary(v1, v2, n);
    for (i = 0; i < n; i++) {
        printf("%d ", v1[i]);
    }
    return 0;
}