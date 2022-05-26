#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[2000000];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i];
    sort(a, a + m);
    for (int i = 0; i < m; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}
