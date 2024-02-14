#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int num[25];
    int i, n, count = 0;
    for (i = 0; i < 25; i++) {
        num[i] = i + 1;
    }
    srand(time(NULL));
    while (count < 25) {
        n = rand() % 25; 
        if (num[n] != 0) {
            printf("%d ", num[n]); 
            num[n] = 0; 
            count++; 
        }
    }
    printf("\n");
    return 0;
}
