#include <stdio.h>
#include <string.h>
#define x 5
#define y 128
void put_strary(const char s[x][y], int n) {
    int i;

    for (i = 0; i < n; i++) {
        if (strcmp(s[i], "$$$$$") == 0) {
        break;
    }
    printf("s[%d] = \"%s\"\n", i, s[i]);
}
}

int main(void) {
    char cs[x][y] = {"Turbo", "NA", "DOHC","$$$$$","123"};
    put_strary(cs, x);

    return 0;
}