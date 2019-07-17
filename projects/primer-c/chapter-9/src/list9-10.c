#include <stdio.h>

int len(const char s[]) {
    int i = 0;

    while (s[i]) {
        i++;
    }

    return i;
}
void del_digit(char s[]) {
    int i, m = 0;

    for (i = 0; i < len(s) ; i++) {
        if (s[i] >= '9' || s[i] <= '0') {
            s[m] = s[i];
            m++;
        }

    }

    s[m] = '\0';

}
int main() {
    char s[10] = "as123dasd";

    del_digit(s);
    printf("%s\n", s);
    return 0;
}