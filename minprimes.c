#include <math.h>
#include <stdio.h>
#define MAXNUMB 100000000

int is_prime(int num) {
    if (num == 0 || num == 1) {
        return 0;
    }
    int prime_flag = 1;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            prime_flag = 0;
            break;
        }
    }
    return prime_flag;
}

int main(void) {
    int x = 1;
    while (x <= MAXNUMB) {
        if (x / 10 == 0) {
            if (is_prime(x)) {
                printf("%d\n", x);
            }
            x++;
            continue;
        }
        int last_digit = x % 10;
        // numbers ending in 0,2,4,5,6,8 are devided either by 2 or 5 so
        // they are not primes and numbers that contain 2,3,5,7 have a
        // subsequence that is a prime, so they are not minimal primes
        if (last_digit != 1 && last_digit != 9) {
            x++;
            continue;
        }
        // numbers containing 2,3,5,7 are not minimal primes
        int copy_x = x;
        int count_digits = 0;
        while (copy_x != 0) {
            int digit = copy_x % 10;
            if (digit == 2 || digit == 3 || digit == 5 || digit == 7) {
                break;
            }
            copy_x /= 10;
            count_digits++;
        }
        // if x contains one of the digits not allowed then skip all
        // "thousands"
        if (copy_x != 0) {
            x += pow(10, count_digits);
            continue;
        }
        if (!is_prime(x)) {
            x++;
            continue;
        }

        // find all subsequences of the digits of x
        int subseq_flag = 1;
        int max = pow(2, count_digits);
        for (int i = 1; i < max - 1; i++) {
            int mask = i;
            int k = 1;
            int num = x;
            int subseq = 0;
            while (num != 0) {
                if (mask % 2 == 1) {
                    subseq += num % 10 * k;
                    k *= 10;
                }
                num /= 10;
                mask /= 2;
            }
            if (is_prime(subseq)) {
                subseq_flag = 0;
                break;
            }
        }
        if (subseq_flag == 1) {
            printf("%d\n", x);
        }
        x++;
    }

    return 0;
}
