#include <iostream>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long int a, b;
        std::cin >> a >> b;
        if (2*b - a < 0 || (2*b - a) % 3 != 0 || (2*a - b) < 0 || (2*a - b) % 3 != 0) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;
        }
    }

}
