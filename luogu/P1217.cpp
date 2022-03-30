//
// Created by wang on 2022/3/24.
//
#include <iostream>
using namespace std;

bool isPrime(int x) {
    if (x==2) return true;
    for(int i = 3; i * i <= x; i+=2) {
        if (x%i==0) return false;
    }
    return true;
}

bool isPalindrome(int x) {
    int y = x; int num = 0;
    while(y > 0) {
        num = num*10 + y%10;
        y /= 10;
    }
    return x==num;
}

int main() {
    int a, b;
    cin >> a >> b;
    if(b > 9989899) b = 9989899;
    for (int i = 5; i <= b; i+=2) {
        if(i < a) continue;
        if(isPalindrome(i) && isPrime(i)) cout << i << endl;
    }
    return 0;
}
