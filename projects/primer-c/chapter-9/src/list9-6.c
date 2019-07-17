#include <stdio.h>

int len(const char s[]) {
    int i = 0;

    while (s[i]) {
        i++;
    }

    return i;
}
int str_chnum(const char s[], int c) {
    int i, p = 0;

    for (i = 0; i < len(s); i++) {
        if (s[i] == c) {
            p ++;
        }

    }

    return p;
}
int main() {
    char s[10] = "asdsassd";
    char c = 's';
    printf("%d\n", str_chnum(s, c));
    return 0;
}