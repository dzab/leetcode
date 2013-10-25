#include <cstdio>
#include <stdint.h>
#include <vector>
#include <algorithm>
using std::vector;
//unique-paths

int uniquePaths(int m, int n) {
    if (m <= 1 || n <= 1) return 1;
    if (m > n) std::swap(n, m);
    vector<int> v(m+n-1, 0);
    vector<int> vp(m+n-1, 0);
    vp[0] = 1;
    for (int i = 1; i <= m+n-2; ++i) {
        v[0] = 1;
        for (int j = 1; j <= i; ++j) {
            v[j] = vp[j-1] + vp[j];
        }
        std::for_each(v.begin(), v.end(), [](int a){ printf("%d ", a); });
        printf("\n");
        v.swap(vp);
    }
    return vp[m-1];
}

int main()
{
    int n = 0, m = 0;
    scanf("%d,%d", &n, &m);
    printf("%d\n", uniquePaths(n,m));
    return 0;
}
    
