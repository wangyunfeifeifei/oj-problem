//
// Created by wang on 2022/3/24.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 2; i <= n; i++) {
        if(n%i==0) {
            cout << n/i << endl;
            break;
        }
    }
    return 0;
}
