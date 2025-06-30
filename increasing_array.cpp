#include <iostream>
#include <vector>
int main() {

    long long int n, ans = 0;
    std::cin >> n;
    std::vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++) {
        std::cin >> arr[i];
        if (i > 0 && arr[i] < arr[i - 1]) {
            ans += arr[i-1] - arr[i];
            arr[i] = arr[i-1];
        }
    }
    std::cout << ans << std::endl;
    return 0;
}