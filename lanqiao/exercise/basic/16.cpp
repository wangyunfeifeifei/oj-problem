#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    vector<bool> digits(b+1, true);
    vector<int> primes;
    for(int i = 2; i < digits.size(); i++) {
        primes.push_back(i);
        for(int j = i + i; digits[i] && j < digits.size(); j += i) {
            digits[j] = false;
        }
    }
    for(int i = a; i <= b; i++) {
        printf("%d=", i);
        int k = i;
        bool f = true;
        for(int j = 0; k > 0 && j < primes.size(); j++) {
            while(k%primes[j]==0) {
                if(f) {
                    printf("%d", primes[j]);
                    f = false;
                } else {
                    printf("*%d", primes[j]);
                }
                k/=primes[j];
            }
        }
        printf("\n");
    }

    return 0;
}
