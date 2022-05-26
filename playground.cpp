#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <map>
#include <tuple>


using namespace std;

int main() {
    int a, b;
    tie(ignore, a, b) = make_tuple(3.3, 1, 2);
    cout << a << " " << b << endl;

    return 0;
}