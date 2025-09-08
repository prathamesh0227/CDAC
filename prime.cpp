#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false; // 0 and 1 are not prime numbers
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; // num is divisible by i, so it's not prime
        }
    }
    return true; // num is prime
}

int main() {
    cout << "Prime numbers up to 100 are:\n";
    for (int i = 2; i <= 100; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
