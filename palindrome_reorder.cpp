#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    std::vector<int> v(26, 0);
    for (char c: s) {
        v[c - 'A']++;
    }
    int num_odds = 0, odd_idx = -1;
    for (int i = 0; i < 26; i++) {
        if (v[i] % 2 != 0) {
            num_odds++;
            odd_idx = i;
        }
        if (num_odds > 1) {
            std::cout << "NO SOLUTION" << std::endl;
            return 0;
        }
    }
    std::string left, mid ;
    for (int i = 0; i < 26; i++) {
        left += std::string(v[i] / 2, i + 'A');
    }
    if (odd_idx != -1) {
        mid += char('A' + odd_idx);
    }
    std::string right = left;
    std::reverse(right.begin(), right.end());
    std::cout << left + mid + right;
    return 0;
}
