#include <cstdio>

int prime[100001] = {0};

void sieve() {
    prime[0] = 1;
    prime[1] = 1;
    for (int i = 2; i <= 100000; i++) {
        for (int j = 2 * i; j <= 100000; j += i) {
            prime[j] = 1;
        }
    }
}

int main() {
    sieve();
    int n;
    scanf("%d", &n);
    int t;
    bool first = true;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        if (prime[t] == 0 && first) {
            printf("%d", t);
            first = false;
        } else if (prime[t] == 0) {
            printf(" %d", t);
        }
    }
    printf("\n");

    return 0;
}
