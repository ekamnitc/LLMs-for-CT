#include <stdio.h>
#include <string.h>

int main() {

    int x, y;
    scanf("%d %d", &y, &x);
    char z[100];
    scanf("%s", z);
    z[x-1] += 32;
    printf("%s", z);

    return 0;
}