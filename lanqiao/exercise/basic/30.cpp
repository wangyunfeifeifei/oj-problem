#include <iostream>
using namespace std;

int a[10005] = {0};
int len = 0;
void calc(int n) {
    for(int i = 0; i < len; i++) {
        a[i] *= n;
    }
    for(int i = 0; i < len; i++) {
        if(a[i] > 9) {
            a[i+1] += a[i]/10;
            a[i] %= 10;
            if(i == len-1) {
                len ++;
            }
        }
    }
}

int main() {
    a[0] = 1;
    len = 1;
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        calc(i);
    }
    for(int i = len-1; i >= 0; i--) {
        cout << a[i];
    }
    cout << endl;
}
