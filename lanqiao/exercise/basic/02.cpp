#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int a[1000];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    for(int i = 0; i < n; i++) {
        if(i==n-1) {
            cout << a[i] << endl;
        } else {
            cout << a[i] << " ";
        }
    }
    return 0;
}
