#include <iostream>
#include <cstring>
using namespace std;

int a[105] = {0};
int len1 = 0;
int b[105] = {0};
int len2 = 0;
int c[105] = {0};
int len3 = 0;
void calc() {
    len3 = len1 > len2 ? len1 : len2;
    for(int i = 0; i < len3; i++) {
        c[i] = a[i] + b[i];
    }
    for(int i = 0; i < len3; i++) {
        if(c[i] > 9) {
            c[i+1] += c[i]/10;
            c[i] %= 10;
            if(i==len3-1) {
                len3++;
            }
        }
    }
}

int main() {
    char sa[105];
    char sb[105];
    scanf("%s%s", sa, sb);
    len1 = strlen(sa);
    len2 = strlen(sb);
    for(int i = 0; i < len1; i++) a[i] = sa[len1-1-i]-'0';
    for(int i = 0; i < len2; i++) b[i] = sb[len2-1-i]-'0';
    calc();
    for(int i = len3-1; i >= 0; i--) {
        printf("%d", c[i]);
    }
    printf("\n");
    return 0;
}
