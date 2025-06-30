#include<cstdio>

int main() {
    long long int n;
    scanf("%lld",&n);
    long long int sum_of_nums = n * (n + 1) / 2, curr_sum = 0;
    n-=1;
    while (n--) {
        long long int temp;
        scanf("%lld",&temp);
        curr_sum += temp;

    }
    printf("%lld\n",sum_of_nums - curr_sum);
    return 0;
}