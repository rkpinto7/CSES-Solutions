#include <iostream>

int main() {
    long long int n;
    std::cin >> n;
    for (long long int i = 1; i <= n; i++) {
        if (i == 1) {
            std::cout << 0 << std::endl;
        } else if (i == 2) {
            std::cout << 6 << std::endl;
        } else {
            std::cout << (i*i)*(i*i - 1)/2 - 4*(i-1)*(i-2) << std::endl;
        }
    }
    return 0;
}
