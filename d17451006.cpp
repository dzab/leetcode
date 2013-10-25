#include <cstdio>
#include <vector>
#include <algorithm>

int numTrees(int n)
{
    if (n <= 1) return 1;
    std::vector<int> v(n+1, 0);
    v[0] = v[1] = 1;
    for (int k = 2; k <= n; ++k) {
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += v[i]*v[k-i-1];
        }
        v[k] = sum;
    }
    return v[n];
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", numTrees(n));
    return 0;
}
