#include <stdio.h>

void put_stringn(const char s[], int n) {
int i;
for(i=0;i<n;i++)
{
printf("%s",s);
}
printf("\n");
}

int main() {
    char s[100] = "asdasd";
    int c = 5;
    put_stringn(s, c);
    return 0;
}