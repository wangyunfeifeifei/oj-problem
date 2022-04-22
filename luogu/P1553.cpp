#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string expr;
    cin >> expr;
    auto pos = expr.find('.');
    if (pos != string::npos) {
        reverse(expr.begin(), expr.begin() + pos);
        reverse(expr.begin() + pos + 1, expr.end());
        int i = 0;
        int j = expr.size() - 1;
        while (expr[i] == '0') i++;
        while (expr[j] == '0') j--;
        if (expr[i] == '.') cout << 0;
        while (i <= j) cout << expr[i++];
        if (expr[j] == '.') cout << 0;
        cout << endl;
        return 0;
    }
    pos = expr.find('/');
    if (pos != string::npos) {
        reverse(expr.begin(), expr.begin() + pos);
        reverse(expr.begin() + pos + 1, expr.end());
        int i = 0;
        while (expr[i] == '0')i++;
        if (i == pos) cout << 0;
        while (i <= pos)cout << expr[i++];
        while (expr[i] == '0')i++;
        while (i < expr.size()) cout << expr[i++];
        cout << endl;
        return 0;
    }
    pos = expr.find('%');
    if (pos != string::npos) {
        reverse(expr.begin(), expr.begin() + pos);
        int i = 0;
        while (expr[i] == '0')i++;
        if (expr[i] == '%') cout << 0;
        while (i < expr.size())cout << expr[i++];
        cout << endl;
        return 0;
    }
    reverse(expr.begin(), expr.end());
    int i = 0;
    while (expr[i] == '0')i++;
    if (i == expr.size()) cout << 0;
    while (i < expr.size()) cout << expr[i++];
    return 0;
}
