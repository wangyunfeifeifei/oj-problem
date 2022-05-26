#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string str;
    int id = 0;
    string m = "";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        if (str.size() > m.size() || str.size() == m.size() && str > m) {
            m = str;
            id = i;
        }
    }
    cout << id << endl << m << endl;
    return 0;
}
