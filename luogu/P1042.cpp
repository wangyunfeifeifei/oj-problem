#include <cmath>
#include <cstdio>

#define N 70000

char str[N];
int k = 0;

void display(int n) {
    int w = 0, l = 0;
    for (int i = 0; i < k; i++) {
        if (str[i] == 'W') w++;
        else if (str[i] == 'L') l++;
        if (abs(w - l) >= 2 && (w >= n || l >= n)) {
            printf("%d:%d\n", w, l);
            w = 0;
            l = 0;
        }
    }
    printf("%d:%d\n", w, l);
}

int main() {
    char ch;
    while (scanf("%c", &ch) && ch != 'E') {
        if (ch == '\n') continue;
        str[k++] = ch;
    }
    display(11);
    printf("\n");
    display(21);

    return 0;
}
