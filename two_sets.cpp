#include <iostream>
#include <vector>

void print_ans(const std::vector<long long int>& bucket1, const std::vector<long long int>& bucket2) {
    std::cout << bucket1.size() << std::endl;
    for (auto num1 : bucket1) {
        std::cout << num1 << ' ';
    }
    std::cout << std::endl;
    std::cout << bucket2.size() << std::endl;
    for (auto num2 : bucket2) {
        std::cout << num2 << ' ';
    }
}

int main() {
    long long int n;
    std::cin >> n;

    std::vector<long long int> bucket1, bucket2;
    if ( n  % 4 == 3) {
        std::cout << "YES" << std::endl;
        for (long long int i = 1; i <= n; i++) {
            if (i % 4 == 0 || i % 4 == 3) {
                bucket1.push_back(i);
            } else {
                bucket2.push_back(i);
            }
        }
        print_ans(bucket1, bucket2);
    } else if (n % 4 == 0) {
        std::cout << "YES" << std::endl;
        for (long long int i = 1; i <= n; i++) {
            if (i % 4 == 1 || i % 4 == 0) {
                bucket1.push_back(i);
            } else {
                bucket2.push_back(i);
            }
        }
        print_ans(bucket1, bucket2);
    }
    else {
        std::cout << "NO" << std::endl;
    }
}
