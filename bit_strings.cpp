#include <iostream>
const long long int MOD = 1000000007;

long long int  bin_pow(long long int i) {
    long long int res = 1;
    if (0 == i) return 1;
    if (i % 2 == 0) {
        res = ((bin_pow(i / 2)% MOD) * (bin_pow(i / 2) % MOD)) % MOD;
    } else {

        res = 2 * ((bin_pow( (i-1) / 2)% MOD) * (bin_pow( (i-1) / 2) % MOD)) % MOD;
    }
    return res;
}

int main() {
    long long int n;
    std::cin >> n;
    std::cout << bin_pow(n) << std::endl;
    return 0;


}
