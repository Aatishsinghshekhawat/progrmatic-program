#include <stdio.h>
#include <stdbool.h>

bool is_prime(int number) {
    for (int i = 2; i < number; i++) {
        if (number % i == 0)
            return false;
    }
    return true;
}

int main() {
    int num = 7;
    if (is_prime(num))
        printf("%d is prime\n", num);
    else
        printf("%d is not prime\n", num);

    return 0;
}
