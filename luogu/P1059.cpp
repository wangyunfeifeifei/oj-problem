#include <iostream>

using namespace std;

int main() {
    int n;
    int a[101];
    int out[101];
    int buc[1005] = {0};

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        buc[a[i]]++;
    }
    int t = 0;
    for (int i = 0; i <= 1000; i++) {
        if (buc[i] > 0) {
            out[t++] = i;
        }
    }

    cout << t << endl;
    for (int i = 0; i < t; i++) {
        cout << out[i] << " ";
    }
    cout << endl;

    return 0;
}
