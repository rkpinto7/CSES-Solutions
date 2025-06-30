# include <iostream>
# include <string>
int main() {
    std::string s;
    std::cin >> s;
    long long int n = s.length(), max_streak = 1, curr_streak = 1;

    for (long long int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            curr_streak++;
        } else {
            max_streak = std::max(max_streak, curr_streak);
            curr_streak = 1;
        }
    }
    max_streak = std::max(max_streak, curr_streak);
    std::cout << max_streak;

    return 0;

}