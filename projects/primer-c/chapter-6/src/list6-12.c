#include <stdio.h>
void mat_mul(const int a[4][3], const int b[3][4], int c[3][3]) {
    int i, j, m;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            int sum = 0;

            for (m = 0; m < 4; m++) {
                sum += b[i][m] * a[m][j];
            }

            c[i][j] = sum;

        }
    }
}
int main() {
    int x, i, j;
    int a[4][3] = {0};
    int b[3][4] = {0};
    int c[3][3] = {0};
    printf("请输入a矩阵的值：");

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            printf("矩阵的第%d行,第%d列的值：", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }



    printf("请输入b矩阵的值：");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("矩阵的第%d行,第%d列的值：", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }

    printf("矩阵a的值\n");

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);
        }

        printf("\n");
    }

    printf("矩阵b的值\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", b[i][j]);
        }

        printf("\n");
    }

    mat_mul(a,  b,  c);
    printf("矩阵c的值\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", c[i][j]);
        }

        printf("\n");
    }

    return 0;
}