#include <iostream>
int main() {
    long long int t;
    std::cin >> t;
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (t--) {
        long long int x, y, ans = 0;
        std::cin >> x >> y;
        if (x <= y) {
            if (y % 2 == 0) {
                ans = (y-1)*(y-1) + (x);
            } else {
                ans = (y)*(y) - (x-1);
            }
        } else {
            if (x % 2 == 0) {
                ans = (x)*(x) - (y-1);
            } else {
                ans = (x-1)*(x-1) + (y);
            }
        }

        std::cout << ans << std::endl;
    }
}