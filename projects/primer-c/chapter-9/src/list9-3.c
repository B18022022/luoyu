#include <stdio.h>
#include <string.h>
# define n 5
int main(void) {
    int i, flag = 0;
    char s[n][128];

    for (i = 0; i < n; i++) {
        printf("s[%d] : ", i);
        scanf("%s", s[i]);

        if (strcmp(s[i], "$$$$$") == 0) {
            flag = n  - i;
            break;
        }
    }

    for (i = 0; i < n - flag; i++) {

        printf("s[%d] = \"%s\"\n", i, s[i]);
    }

    return 0;
}