#include <cstdio>

bool isPalindrome(int x) {
    if (x < 0) return false;
    long long y = 0;
    int n = x; 
    while (n != 0) {
        y = y*10 + n%10;
        n /= 10;
    }
    return (x==y);
}

bool isPalindrome2(int x) {
    if (x < 0) return false;
    int div = 1;
    while (x/div >= 10) {
        div *= 10;
    }
    while (x != 0) {
        int l = x / div;
        int r = x % 10;
        if (l != r) return false;
        x = (x % div) / 10;
        div /= 100;
    }
    return true;
}

int main()
{
    printf("%d\n", isPalindrome2(12321));
    return 0;

}
