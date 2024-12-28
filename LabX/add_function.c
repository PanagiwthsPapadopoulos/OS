#include <stdio.h>

void add(int *a, int *b, int *c, int *result) {
    *result = *a + *b + *c;
}

int main() {
    int a = 5, b = 10, c = 15, result;
    add(&a, &b, &c, &result);
    printf("Sum: %d\n", result);
    return 0;
}
