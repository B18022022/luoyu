#include <stdio.h>
int search_idx(const int v[], int idx[], int key, int n) {
    int i, j = 0;
    for (i = 0; i < n; i++) {
        if (key == v[i]) {
            idx[j] = i;
            j++;
        }

    }
    return j;
}
int main() {
    int i, n, key;
    int v[100];
    int idx[100];
    printf("请输入数组的个数:");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("第%d个数字:", i + 1);
        scanf("%d", &v[i]);
    }
    printf("请输入key的值:");
    scanf("%d", &key);
    for (i = 0; i < search_idx(v, idx, key, n); i++) {
        printf("%d ", idx[i]);
    }
    return 0;
}